//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14vXUqAGMCFAYD&categoryId=AV14vXUqAGMCFAYD&categoryType=CODE
//SW 미로찾기

#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

#define SIZE 16

int map[SIZE][SIZE];
int escape = 0;

void fun(int x, int y) {
	if (x<0 || y<0 || x>SIZE || y>SIZE)
		return;

	if (map[x][y] == 3)
		escape = 1;

	else if (map[x][y] == 0||map[x][y]==2) {
		map[x][y] = 9;

		if (escape == 0)
			fun(x - 1, y);
		if (escape == 0)
			fun(x, y + 1);
		if (escape == 0)
			fun(x + 1, y);
		if (escape == 0)
			fun(x, y - 1);

		map[x][y] = 0;
	}
}

int main() {
	int t;
	for (int i = 0; i < 1; i++) {
		cin >> t;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				cin >> map[i][j];
			}
		}
		fun(1, 1);
		cout << "#" << t << " " << escape << endl;
	}
	return 0;
}
