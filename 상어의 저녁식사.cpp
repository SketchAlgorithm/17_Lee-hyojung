#include <iostream>
using namespace std;

int n;
class shark {
public:
	int size;
	int speed;
	int intel;
};
shark sharks[50];
bool caneat[50][50];
int amatch[50];
int bmatch[50];

int visit[50];
int vcount = 1;

bool dfs(int a) {
	if (visit[a] == vcount) {
		return false;
	}
	visit[a] = vcount;
	for (int i = 0; i < n; i++) {
		if (caneat[a][i]) {
			if (bmatch[i] == -1 || dfs(bmatch[i])) {
				amatch[a] = i;
				bmatch[i] = a;
				return true;
			}
		}
	}
	return false;
}
int bimatch() {
	int size = 0;

	for (int i = 0; i < n; i++) {
		amatch[i] = -1;
		bmatch[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		vcount++;
		size += dfs(i);
		vcount++;
		size += dfs(i);
	}
	return size;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sharks[i].size >> sharks[i].speed >> sharks[i].intel;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			if (sharks[i].size == sharks[j].size&&
				sharks[i].speed == sharks[j].speed&&
				sharks[i].intel == sharks[j].intel&&
				i>j) {
				continue;
			}
			if (sharks[i].size >= sharks[j].size&&
				sharks[i].speed >= sharks[j].speed&&
				sharks[i].intel >= sharks[j].intel) {
				caneat[i][j] = 1;
			}
		}
	}
	int count = bimatch();
	cout << n - count << endl;

	return 0;
}