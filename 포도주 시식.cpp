//https://www.acmicpc.net/problem/2156
//포도주 시식
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n;
int wine[10000];
int cache[10000];

int max2(int x,int y,int z) {
	if (x > y)
		if (x > z)
			return x;
		else
			return z;
	else
		if (y > z)
			return y;
		else
			return z;
}

int fun(int last) {
	if (last == 0)
		return wine[0];
	else if (last == 1)
		return wine[0] + wine[1];

	int& ret = cache[last];
	if (ret != -1)
		return ret;

	ret = max2(fun(last - 1),fun(last - 2) + wine[last],fun(last - 3) + wine[last - 1] + wine[last]);
	return ret;
}

int main() {
	cin >> n;
	memset(wine, -1, sizeof(wine));
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < n; i++) {
		cin >> wine[i];
	}

	//for (int i = 0; i < n; i++) {
	//	cout << fun(i) << " ";
	//}
	cout << fun(n-1) << endl;

	return 0;
}