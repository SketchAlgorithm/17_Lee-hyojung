//BRACKETS2
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int c;
char str[10000];
vector<char> open;

void func() {
	cin >> str;
	bool pair;

	int len = 0;//���ڿ�����
	while (str[len])
		len++;

	for (int i = 0; i < len; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {//���� ��ȣ
			open.push_back(str[i]);
		}
		else {//���� ��ȣ
			if (open.empty())
				pair = false;
			else {
				char top = open.back();

				switch (str[i]) {
				case ')':
					if (top == '(') {
						pair = true;
						open.pop_back();
					}
					break;
				case '}':
					if (top == '{') {
						pair = true;
						open.pop_back();
					}
					break;
				case ']':
					if (top == '[') {
						pair = true;
						open.pop_back();
					}
					break;
				default:
					pair = false;
					break;
				}
			}
		}
	}

	if (!open.empty())//������� ������ ¦�� �ȸ���
		pair = false;

	if (pair)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	open.clear();
}

int main() {
	cin >> c;
	while (c-- > 0) {
		func();
	}
	return 0;
}