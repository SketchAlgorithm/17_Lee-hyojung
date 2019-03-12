#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int cache[101][101];
string W, S;
int n;

bool wildcard(int w, int s) {
	int &ret = cache[w][s];
	if (ret != -1)return ret;

	while (s < S.size() && w < W.size()&& (W[w] == '?' || W[w] == S[s])) {
		s++;
		w++;
	}
	if (w == W.size() && s == S.size())
		return 1;
	if (W[w] == '*') {
		//for (int skip = 0; skip + s <= S.size(); skip++) {
		//	if (wildcard(w + 1, s + skip))
		if(wildcard(w+1,s)||(s<S.size()&&wildcard(w,s+1)))
				return ret = 1;

	}
	return ret = 0;
}

int main() {
	int c;
	vector<string> ans;
	cin >> c;
	while (c-- > 0) {
		cin >> W;
		cin >> n;
		ans.clear();
		for (int i = 0; i < n; i++) {
			memset(cache, -1, sizeof(cache));
			cin >> S;
			if (wildcard(0, 0)==1)
				ans.push_back(S);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << endl;
		}
	}
	return 0;
}