#include <iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int count = 0;
		int a = i / 100;//100자리 수
		int b = i / 10;//10자리 수
		int c = i % 10;//1자리수
		if ((a==3||b==3||c==3)|| (a == 6 || b == 6 || c == 6) ||(a == 9 || b == 9 || c == 9)) {
			count++;
			for (int j = 0; j < count; j++) {
				cout << "-";
			}
			cout << " ";
		}
		else {
			cout << i<<" ";
		}
	}
	return 0;
}