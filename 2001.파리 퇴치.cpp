//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PzOCKAigDFAUq&categoryId=AV5PzOCKAigDFAUq&categoryType=CODE

#include <iostream>
using namespace std;

//n:5~15
//m:2~n
//각 칸 파리<=30
int T;
int n, m;
int map[15][15];
int fly = 0;
int pro = 0;

void fun(int x,int y) {
	int sum = 0;

	for (int i = x; i < x + m; i++) {
		for (int j = y; j < y + m; j++) {
			sum += map[i][j];
		}
	}
	if (sum > fly)
		fly = sum;
}

int main() {
	cin >> T;
	while (T-- > 0) {
		//입력
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fun(i,j);
			}
		}
		pro++;
		cout << "#" << pro <<" " << fly << endl;
	}
	return 0;
}