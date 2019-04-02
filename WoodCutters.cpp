//http://codeforces.com/problemset/problem/545/C
//C.WoodCutters (codeforces)

#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;


int n;//���� ���� : 1~100000
int pos[100010];//������ ��ġ�� ��� �迭
int height[100010];//������ ���̸� ��� �迭

int main() {
	//�Է�
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> pos[i] >> height[i];//x�� h �Է� �� �� �迭 ����
	}

	//����
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
		//�������� �Ѿ�߸��� ���
		if (pos[i] - height[i] > pos[i - 1]) {
			ans++;
			/*pos[i] -= height[i];*/
		}
		//���������� �Ѿ�߸��� ���
		else if (pos[i] + height[i] < pos[i + 1]) {
			ans++;
			pos[i] += height[i];
		}
	}
	
	cout << ans << endl;

	return 0;
}