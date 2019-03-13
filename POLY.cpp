//POLY
#include <iostream>
#include <string.h>
using namespace std;

int c;//1~50
int n;//1~100
int cache[101][101] = {0};
const int MOD = 10000000;

int poly(int n, int bottom) {
	int& ret = cache[n][bottom];

	if (n == bottom)
		return ret = 1;

	if (ret != -1)
		return ret;

	ret = 0;

	int blocks = n - bottom;
	for (int i = 1; i <= blocks; i++) {
		ret += (i + bottom - 1)*poly(blocks, i);
		ret %= MOD;
	}
	return ret;
}

int main() {
	cin >> c;
	while (c-- > 0) {
		cin >> n;
		memset(cache, -1, sizeof(cache));
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res+=poly(n, i);
			res %= MOD;
		}
		cout << res << endl;
	}
	return 0;
}