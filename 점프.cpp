#include <iostream>
using namespace std;

int n;
long long cmap[101][101];
int map[101][101];

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cmap[0][0] = 1;//Ω√¿€

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (map[i][j] == 0)
				continue;

			if (i + map[i][j] < n) {
				cmap[i + map[i][j]][j] += cmap[i][j];
			}
			if (j + map[i][j] < n) {
				cmap[i][j + map[i][j]] += cmap[i][j];
			}

		}
	}

	cout << cmap[n - 1][n - 1] << endl;

	return 0;
}