//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV13zo1KAAACFAYh&categoryId=AV13zo1KAAACFAYh&categoryType=CODE

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
vector<int> score(1000);//0~100

int pro;

void fun() {
	vector<int> carr(101);
	for (int i = 0; i < score.size(); i++) {
		for (int j = 0; j < carr.size(); j++) {
			if (score[i] == j) {
				carr[j]++;
			}
		}
	}

	int maxi = 0;
	for (int i = 0; i < carr.size(); i++) {
		if (carr[i] > carr[maxi]) {
			maxi = i;
		}
	}
	cout << "#" << pro << " "<<maxi << endl;
}

int main() {
	cin >> T;
	while(T-->0) {
		//ют╥б
		cin >> pro;
		for (int i = 0; i < score.size(); i++) {
			cin >> score[i];
		}
		fun();
	}
	return 0;
}