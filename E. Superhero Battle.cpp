//http://codeforces.com/contest/1141/problem/E

#include <iostream>
using namespace std;

long long H;
int n;
int narr[200000];
long long sum = 0;//�� �� ������ �ּ���
long long c = 0;//count
long long msum = 0;

//���� ��
//void fight() {
//	while (H >= 0) {
//		if (c == n) {
//			c = 0;
//		}
//		for (int i = c; i < n; i++) {
//			H += narr[i];
//			if (H < 0) {
//				cp++;
//				break;
//			}
//			cp++;
//			c++;
//			cout << cp << endl;
//		}
//	}
//}

//���� ��
void fight() {
	for (int i = 0; i < n; i++) {
		sum += narr[i];
		if (sum < msum)
			msum = sum;
	}
	//���ѷ����� ���� ���
	if (sum >= 0 && msum + H > 0) {
		c = -1;
		return;
	}
	else {
		//�� �� �������� �� ������ ���
		if (msum + H > 0) {
			c = ((H + msum) / -sum) + (bool)((H + msum) % -sum);
			H += c * sum;
			c *= n;
		}
		for (int i = 0; H > 0; i++) {
			H += narr[i];
			c++;
		}
		return;
	}
}
int main() {
	//�� �Է�
	cin >> H >> n;
	for (int i = 0; i < n; i++){
		cin >> narr[i];
	}

	fight();
	cout << c << endl;
	return 0;
}