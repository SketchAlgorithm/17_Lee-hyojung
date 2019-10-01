//https://www.acmicpc.net/problem/11404

#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 100001;

int n,m;
int map[101][101];

void floyd() {
	//���İ��� ���
	for (int k = 1; k < n+1; k++) {
		for (int i = 1; i < n + 1; i++) {//i ��忡��
			for (int j = 1; j < n+1; j++) {//j ����
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
}

int main() {

	cin >> n >> m;
	//map �ʱ�ȭ

	//memset(map, INF, sizeof(map));
	for (int i = 1; i < n + 1; i++){
		for (int j = 1; j < n + 1; j++) {
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (map[a][b] == 0) {//�� ��
			map[a][b] = c;
		}
		else {//�̹� ��ϵ� ���� �ִ� ���
			//map�� ���� ���� �Էµ� �� �� �ּ� ����
			map[a][b] = min(map[a][b], c);
		}
	}

	floyd();

	//���
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (map[i][j] == INF)
				cout << 0 << " ";
			else 
				cout << map[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}