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

	int len = 0;//문자열길이
	while (str[len])
		len++;

	for (int i = 0; i < len; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {//시작 괄호
			open.push_back(str[i]);
		}
		else {//종료 괄호
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

	if (!open.empty())//비어있지 않으면 짝이 안맞음
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