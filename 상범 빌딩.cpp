#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

const int MAX = 30;

typedef struct {
	int z, y, x;
}Dir;

Dir moveDir[6] = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };

//빌딩 층 수, 한 층의 행, 한층의 열
int L, R, C;

pair<pair<int, int>, int> start, finish;//시작점, 도착점
int cube[MAX][MAX][MAX];

int BFS(pair<pair<int, int>, int>start) {
	queue<pair<pair<int, int>, pair<int, int>>> q;//z,y,x,cnt
	bool visited[MAX][MAX][MAX];
	q.push({ { start.first.first,start.first.second }, {start.second,0} });

	memset(visited, false, sizeof(visited));//visited 초기화
	visited[start.first.first][start.first.second][start.second] = true;

	while (!q.empty()) {
		int z = q.front().first.first;
		int y = q.front().first.second;
		int x = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		//도착한 경우
		if (z == finish.first.first && y == finish.first.second && x == finish.second) {
			return cnt;
		}

		for (int i = 0; i < 6; i++) {
			int nextZ = z + moveDir[i].z;
			int nextY = y + moveDir[i].y;
			int nextX = x + moveDir[i].x;

			//범위 내에 있고
			if (nextZ >= 0 && nextZ < L && nextY >= 0 && nextY < R && nextX >= 0 && nextX < C) {
				//방문하지 않았으며 벽이 아닌 공간
				if (visited[nextZ][nextY][nextX] == false && cube[nextZ][nextY][nextX] == 0) {
					//일 때만 큐에 넣는다.
					visited[nextZ][nextY][nextX] = true;
					q.push({ {nextZ,nextY},{nextX,cnt + 1} });
				}
			}
		}
	}

	//도착하지 못한 경우
	return -1;
}

int main() {
	//cin 속도향상
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	while (1) {
		memset(cube, 0, sizeof(cube));
		cin >> L >> R >> C;

		//입력의 끝은 L,R,C가 모두 0으로 표현된다.(문제)
		if (!L && !R && !C) {
			break;
		}

		//맵 정보 입력
		for (int z = 0; z < L; z++) {//층
			for (int y = 0; y < R; y++) {//행
				string tmp;
				cin >> tmp;

				for (int i = 0; i < tmp.length(); i++) {
					if (tmp[i] == 'S') {
						start.first.first = z;
						start.first.second = y;
						start.second = i;
					}
					else if (tmp[i] == '#')
						cube[z][y][i] = 1;
					else if (tmp[i] == 'E') {
						finish.first.first = z;
						finish.first.second = y;
						finish.second = i;
					}
				}

			}
		}

		int result = BFS(start);
		if (result == -1) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << result << " minute(s).\n";
		}
	}

	return 0;
}