#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n;//2~100
int map[100][100];
int cache[100][100];

int fun(int x,int y) {
	if (x == n - 1)
		return map[x][y];

	int& ret = cache[x][y];
	if (ret != -1)
		return ret;
		
	return ret = max(map[x][y] + fun(x + 1, y), map[x][y] + fun(x + 1, y + 1));
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> map[i][j];
			}
		}

		cout << fun(0, 0) << endl;

	}
	return 0;
}