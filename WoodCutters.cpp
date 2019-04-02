//http://codeforces.com/problemset/problem/545/C
//C.WoodCutters (codeforces)

#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;


int n;//나무 개수 : 1~100000
int pos[100010];//나무의 위치를 담는 배열
int height[100010];//나무의 높이를 담는 배열

int main() {
	//입력
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> pos[i] >> height[i];//x와 h 입력 후 각 배열 저장
	}

	//실행
	int ans = 0;
	if (n == 1) {
		ans = 1;
		cout << ans << endl;
		return 0;
	}
	if (n == 0) {
		ans = 0;
		cout << ans << endl;
		return 0;
	}
		
	 ans = 2;
	for (int i = 2; i<n; i++) {
		//왼쪽으로 넘어뜨리는 경우
		if (pos[i] - height[i] > pos[i - 1]) {
			ans++;
			/*pos[i] -= height[i];*/
		}
		//오른쪽으로 넘어뜨리는 경우
		else if (pos[i] + height[i] < pos[i + 1]) {
			ans++;
			pos[i] += height[i];
		}
	}
	
	cout << ans << endl;

	return 0;
}