//시험감독
#include <iostream>
using namespace std;

int n;
int b, c;
int room[1000000];
long long ans = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> room[i];
		//총감독관
	}
	cin >> b >> c;

	ans += n;

	for (int i = 0; i < n; i++) {
		room[i] -= b;
		if (room[i] > 0) {
			ans += room[i] / c;
			if (room[i] % c != 0)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}