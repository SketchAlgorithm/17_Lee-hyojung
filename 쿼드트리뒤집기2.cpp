#include <iostream>
#include <cstring>
using namespace std;

int c;
string tmp;

string quad(string::iterator& it) {

	char head = *it;

	it++;

	if (head == 'b'|| head =='w') {
		return string(1,head);
	}
	//else {
		string str1 = quad(it);
		string str2 = quad(it);
		string str3 = quad(it);
		string str4 = quad(it);

		return string("x") + str3 + str4 + str1 + str2;
	//}

}

int main() {

	cin >> c;
	while (c--) {
		cin >> tmp;

		string::iterator it = tmp.begin();

		cout << quad(it);
	}
	return 0;
}