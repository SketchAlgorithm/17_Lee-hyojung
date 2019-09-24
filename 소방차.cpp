#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000;
const int INF = 987654321;

int C;//테스트케이스
//장소 수(vertex), 도로 수(edge), 화재 장소 수, 소방서 수
int V, E, n, m;
vector<pair<int, int>> graph[MAX];
int fire[1000];
int station[1000];

vector<int> dijkstra(int start) {
	vector<int> distance(V+1, INF);
	distance[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int curVertex = pq.top().second;
		pq.pop();

		if (distance[curVertex] < cost)
			continue;

		for (int i = 0; i < graph[curVertex].size(); i++) {
			int neighbor = graph[curVertex][i].first;
			int neighborDistance = cost + graph[curVertex][i].second;

			if (distance[neighbor] > neighborDistance) {
				distance[neighbor] = neighborDistance;
				pq.push(make_pair(-neighborDistance, neighbor));
			}
		}
	}
	return distance;
}

int main() {
	cin >> C;
	while (C--) {
		cin >> V >> E >> n >> m;

		for (int i = 0; i < E; i++) {
			int a, b, t;
			cin >> a >> b >> t;

			//graph[a].push_back(make_pair(b, t));
			graph[a].push_back(make_pair(b, t));
			graph[b].push_back(make_pair(a, t));
		}

		//화재가 발생한 장소
		for (int i = 0; i < n; i++) {
			cin >> fire[i];
		}
		//소방서의 위치 번호
		for (int i = 0; i < m; i++) {
			int sNum;
			cin >> sNum;
			graph[0].push_back(make_pair(sNum, 0));
			graph[sNum].push_back(make_pair(0, 0));
		}

		//vector<int> result = dijkstra(1, V);
		vector<int> result = dijkstra(0);

		int ans = 0;
		for (int i = 0; i < V; i++) {
			ans += result[fire[i]];
		}
		cout << ans << "\n";
	}
	return 0;
}