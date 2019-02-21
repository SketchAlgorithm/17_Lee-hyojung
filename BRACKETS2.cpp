//BRACKETS2
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int c;
char str[10000];
vector<char> open;

bool func() {
	cin >> str;
	bool pair = true;

	int len = 0;//문자열길이
	while (str[len])
		len++;

	for (int i = 0; i < len; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {//시작 괄호
			open.push_back(str[i]);
		}
		else {//종료 괄호
			if (open.empty())
				return false;
			if (!pair)
				return false;
			else {
				char top = open.back();

				switch (str[i]) {
				case ')':
					if (top == '(') {
						open.pop_back();
					}
					else
						pair = false;
					break;
				case '}':
					if (top == '{') {
						open.pop_back();
					}
					else
						pair = false;
					break;
				case ']':
					if (top == '[') {
						open.pop_back();
					}
					else
						pair = false;
					break;
				}
			}
		}
	}

	if (!open.empty()) {//비어있지 않으면 짝이 안맞음
		pair = false;
	}
	return pair;
}

int main() {
	cin >> c;
	while (c-- > 0) {
		open.clear();
		if (func())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
