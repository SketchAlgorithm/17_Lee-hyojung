//WILDCARD
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int c,n;
string w;
vector<string> list;

bool func(string wild,string com) {
	int i1 = 0, i2= 0;

	while (true) {
		if (i1 == wild.size() || i2 == wild.size()) {
			break;
		}
		if (wild[i1] == com[i2]) {
			i1++;
			i2++;
		}
		else if (wild[i1] == '?') {
			i1++;
			i2++;
		}
		else if (wild[i1] == '*') {
			break;
		}
		else if (wild[i1] != com[i2]) {
			return false;
		}
	}
	if (i1 == wild.size() && i2 == com.size())
		return true;
	else if (i1 == wild.size() - 1 && wild[i1] == '*'&&i2 == com.size()) {
		return true;
	}
	else if (i1 == wild.size() || i2 == com.size())
		return false;

	bool check = false;
	if (wild[i1] == '*') {
		string subwild = wild.substr(i1 + 1);
		string tmp; for (int i = i2; i < com.size(); i++) {
			tmp = com.substr(i);
			check = check || func(subwild, com.substr(i));
		}
	}
	return check;
}

int main() {
	vector<string> answer;
	cin >> c;
	while (c-- > 0) {
		cin >> w;
		cin >> n;
		list.clear();
		list.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> list[i];
			if (func(w, list[i]))
				answer.push_back(list[i]);
		}
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << endl;
	}
	return 0;
}