#include <iostream>
#include <algorithm>

using namespace std;

int linked[101][101];
int visited[101];//���� ��ǻ��
int com, pcount;
int vcom = 0;

void dfs(int current) {
	vcom++;
	visited[current] = 1;

	for (int i = 1; i < com + 1; i++) {
		if (linked[current][i] == 1 && visited[i] != 1)
			dfs(i);
	}
}

int main() {
	cin >> com;
	cin >> pcount;
	for (int i = 0; i < pcount; i++) {
		int a, b;
		cin >> a >> b;
		linked[a][b] = 1;
		linked[b][a] = 1;
	}

	dfs(1);//1���� ����

	cout << vcom - 1 << endl;//1�� ��ǻ�� ����

	return 0;
}