#include <iostream>
using namespace std;

int m, n;//����, ����
int arr[1001][1001];//1:���� �丶��, 0:�� ���� �丶��, -1:�丶�� ����
int arr2[1001][1001];
int day,tom, utom, flag;

void init() {
	for (int i = 0; i <= m+1; i++) {
		arr[0][i] = -2;
		arr[n+1][i] = -2;
	}
	for (int i = 0; i <=n; i++) {
		arr[i][0] = -2;
		arr[i][m+1] = -2;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr2[i][j] = arr[i + 1][j + 1];
		}
	}
}
int check() {
	flag = 0;
	tom = 0;
	utom = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 1) {
				tom++;
			}
			else if (arr[i][j] == -1) {
				utom++;
			}
		}
	}
	if (tom == m * n-utom) {
		flag = 1;
	}
	return flag;
}
void fun() {
	day = 0;
	while (check()!=1) {
		if (tom == m * n-utom) {
			day = 0;
			return;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] == 1) {//���� �丶��
					if (arr[i - 1][j] == 0) arr2[i - 2][j-1] = 1;
					if (arr[i][j + 1] == 0) arr2[i-1][j] = 1;
					if (arr[i + 1][j] == 0) arr2[i][j-1] = 1;
					if (arr[i][j - 1] == 0) arr2[i-1][j - 2] = 1;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr2[i - 1][j - 1] == 1) {
					arr[i][j] = arr2[i - 1][j - 1];
				}
			}
		}
		day++;
	}
}

int main() {
	cin >> m >> n;
	init();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	fun();
	cout << day << endl;

	return 0;
}