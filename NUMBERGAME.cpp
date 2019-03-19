//NUMBERGAME 
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int cache[50][50];
int board[50];

int EMPTY = -100000;


int game(int start,int end) {
	if (start > end)
		return 0;
	int& ret = cache[start][end];
	if (ret != EMPTY)
		return ret;

	ret = max(board[start]-game(start+1,end),board[end]-game(start,end-1));

	if (end-start>=1) {
		ret = max(ret, -game(start + 2, end));
		ret = max(ret, -game(start, end - 2));
	}
	return ret;
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				cache[i][j] = EMPTY;
			}
		}
		for (int i = 0; i < 50; i++) {
			board[i] = 0;
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> board[i];
		}
		cout<<game(0, n - 1)<<endl;
	}

	return 0;
}