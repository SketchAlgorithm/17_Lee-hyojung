//≥Ïªˆ ø  ¿‘¿∫ æ÷∞° ¡©¥Ÿ¡ˆ?
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> p;

int id[200][200];
int map[200][200];
int n;
vector<p> mem[20000];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void pre() {
	int cnt = 1;
	for (int i = 1; i <= 125; i++) {
		for (int j = 1; j <= 125; j++) {
			id[i][j] = cnt++;
		}
	}
}

int dijkstra() {
	priority_queue<p> pq;
	pq.push({ 0,0 });
	vector<int> dist(20000, INT_MAX);
	dist[0] = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = -pq.top().first;

		pq.pop();
		if (dist[now] < cost)
			continue;
		
		for (auto i : mem[now]) {
			int nxt = i.first;
			int nxtCost = i.second + cost;
			
			if (dist[nxt] > nxtCost) {
				pq.push({ -nxtCost,nxt });
				dist[nxt] = nxtCost;
			}
		}
	}
	return dist[id[n][n]];
}

void solve(int cnt) {
	//√ ±‚»≠
	for (int i = 0; i < 20000; i++) {
		mem[i].clear();
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	//

	mem[0].push_back({1,map[1][1]});

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];

				if (x < 1 || y<1 || x>n || y>n)
					continue;
				mem[id[i][j]].push_back({ id[x][y],map[x][y] });
			}
		}
	}
	cout << "Problem " << cnt << ": " << dijkstra() << endl;
}

int main() {
	pre();
	int cnt = 1;
	while (1) {
		cin >> n;
		if (n)
			solve(cnt++);
		else
			break;
	}


	return 0;
}