//A. Game 23
#include <iostream>
using namespace std;

int n, m;

int main() {
	cin >> n >> m;
	if (m%n != 0) {
		cout << -1 << endl;
	}
	else {
		int a = m/n;
		int c1 = 0, c2 = 0;
		while (a % 2 == 0) {
			a = a / 2;
			c1++;
		}
		while (a % 3 == 0) {
			a = a / 3;
			c2++;
		}
		cout << c1 + c2 << endl;
	}
	return 0;
}