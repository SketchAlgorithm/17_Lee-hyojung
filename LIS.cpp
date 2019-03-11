//가장 긴 증가하는 부분 수열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> list;
vector<int> answer;
int ans_list[50];
int ans_count = 0;
int ans = 0;

void func() {
	answer.clear();
	answer.push_back(-1);
	for (int i = 0; i < n; i++) {
		int compare = answer.back();
		if (compare < list[i]) {
			answer.push_back(list[i]);
			ans++;
		}
		else if (compare > list[i]) {
			/*int back_compare = answer.back();
			while (back_compare > list[i]) {
				answer.pop_back();
			}
			answer.push_back(list[i]);*/

			vector<int>::iterator it = lower_bound(answer.begin(), answer.end(), list[i]);
			*it = list[i];
		}
	}

	//cout << ans << endl;
	ans_list[ans_count] = ans;
	ans_count++;

	//reverse(answer.begin(), answer.end());
	//for (int i = 1; i < answer.size(); i++)
	//	cout << answer[i] << " ";
	//cout << endl;
}

int main() {
	int T;
	cin >> T;
	while (T-- > 0)
	{
		list.clear();
		ans = 0;
		cin >> n;
		int num;
		for (int i = 0; i < n; i++) {
			cin >> num;
			list.push_back(num);
		}
		func();
	}
	for (int i = 0; i < ans_count;i++) {
		cout << ans_list[i] << endl;
	}
	return 0;
}