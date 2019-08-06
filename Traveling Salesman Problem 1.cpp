//Traveling Salesman Problem 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c,n;
vector<vector<double>> city;

double fun(int node, double dis, vector<int> remainNode) {
	if (remainNode.size() == 1)
		return dis;

	double result = numeric_limits<double>::max();//doubleÇü ÃÖ´ë
	for (int i = 1; i < remainNode.size(); i++) {
		vector<int> eraseNode = remainNode;
		eraseNode.erase(eraseNode.begin() + i);
		result = min(result, fun(remainNode[i], dis + city[node][remainNode[i]],
			eraseNode));
	}
	return result;
}


int main() {
	cin >> c;
	while (c--) {
		cin >> n;
		
		vector<int> remainNode(n + 1, 0);
		city = vector<vector<double>>(n + 1, vector<double>(n + 1, 0));

		for (int i = 1; i < n+1; i++) {
			remainNode[i] = i;
			for (int j = 1; j < n + 1; j++) {
				cin >> city[i][j];
			}
		}

		printf("%.10lf\n", fun(0, 0, remainNode));
	}
	return 0;
}