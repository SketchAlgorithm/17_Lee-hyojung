#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int v, e, k;
vector<vector<int>> matrix;
vector<int> dist;

void dijkstra() {
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (matrix[i][j] != INT_MAX) {//경로 존재
				dist[j] = min(dist[j], dist[i]+matrix[i][j]);
			}
		}
	}
}

int main() {
	cin >> v >> e;
	cin >> k;

	//열생성
	for (int i = 0; i < v; i++) {
		vector<int> col(v,INT_MAX);
		matrix.push_back(col);
	}
	//입력
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		matrix[a-1][b-1] = c;
	}

	//dist 초기화 
	for (int i = 0; i < v; i++) {
		if (i == k - 1)
			dist.push_back(0);//시작점
		else
			dist.push_back(INT_MAX);
	}

	dijkstra();
	for (int i = 0; i < v; i++) {
		if (dist[i] == INT_MAX)
			cout << "INF" << endl;
		else if (i == k - 1)
			cout << 0 << endl;
		else
			cout << dist[i] << endl;
	}

	return 0;
}