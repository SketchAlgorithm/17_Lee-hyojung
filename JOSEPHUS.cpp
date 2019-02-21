//조세퍼스
#include <iostream>
using namespace std;

int c, n, k;//n:3~1000, k:1~1000
int people[1000];//살아있으면 0 죽으면 1

void func(int n, int k) {
	int alive = n-1;
	int who = 0;
	people[0] = 1;

	while (alive > 2) {//살아있는 사람이 2명이 될 때까지 반복
		int ac = 0;
		while (ac != k) {
			if (who == n - 1)
				who -= n-1;
			else {
				who++;
			}

			if (people[who] == 0) {
				ac++;
			}
		}
		people[who] = 1;
		//cout << "dead:" << who << endl;
		alive--;
	}

	for (int i = 0; i < n; i++) {
		if (people[i] == 0)
			cout << i + 1 << " ";
	}
}

int main() {
	cin >> c;
	while (c-- > 0) {
		cin >> n >> k;
		func(n, k);
	}
	return 0;
}
