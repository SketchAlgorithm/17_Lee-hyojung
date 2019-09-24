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

//���� �� ��, �� ���� ��, ������ ��
int L, R, C;

pair<pair<int, int>, int> start, finish;//������, ������
int cube[MAX][MAX][MAX];

int BFS(pair<pair<int, int>, int>start) {
	queue<pair<pair<int, int>, pair<int, int>>> q;//z,y,x,cnt
	bool visited[MAX][MAX][MAX];
	q.push({ { start.first.first,start.first.second }, {start.second,0} });

	memset(visited, false, sizeof(visited));//visited �ʱ�ȭ
	visited[start.first.first][start.first.second][start.second] = true;

	while (!q.empty()) {
		int z = q.front().first.first;
		int y = q.front().first.second;
		int x = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		//������ ���
		if (z == finish.first.first && y == finish.first.second && x == finish.second) {
			return cnt;
		}

		for (int i = 0; i < 6; i++) {
			int nextZ = z + moveDir[i].z;
			int nextY = y + moveDir[i].y;
			int nextX = x + moveDir[i].x;

			//���� ���� �ְ�
			if (nextZ >= 0 && nextZ < L && nextY >= 0 && nextY < R && nextX >= 0 && nextX < C) {
				//�湮���� �ʾ����� ���� �ƴ� ����
				if (visited[nextZ][nextY][nextX] == false && cube[nextZ][nextY][nextX] == 0) {
					//�� ���� ť�� �ִ´�.
					visited[nextZ][nextY][nextX] = true;
					q.push({ {nextZ,nextY},{nextX,cnt + 1} });
				}
			}
		}
	}

	//�������� ���� ���
	return -1;
}

int main() {
	//cin �ӵ����
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	while (1) {
		memset(cube, 0, sizeof(cube));
		cin >> L >> R >> C;

		//�Է��� ���� L,R,C�� ��� 0���� ǥ���ȴ�.(����)
		if (!L && !R && !C) {
			break;
		}

		//�� ���� �Է�
		for (int z = 0; z < L; z++) {//��
			for (int y = 0; y < R; y++) {//��
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