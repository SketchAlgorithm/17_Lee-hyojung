#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 20000 + 1;
const int INF = 987654321;

int V, E, K;
vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int start, int vertex) {
	vector<int> distance(vertex, INF);//정점 개수만큼 거리 초기화
	distance[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cost = -pq.top().first;//거리가 작은 정점부터 꺼내기 위해 부호 변경
		int curVertex = pq.top().second;
		pq.pop();

		//이미 더 작은 경우 넘어간다.
		if (distance[curVertex] < cost)
			continue;

		for (int i = 0; i < graph[curVertex].size(); i++) {
			int neighbor = graph[curVertex][i].first;
			int neighborDistance = cost + graph[curVertex][i].second;

			//최소 경로 발견 시 업데이트
			if (distance[neighbor] > neighborDistance) {
				distance[neighbor] = neighborDistance;
				//거리가 작은 정점부터 꺼내기 위해 부호 변경
				pq.push(make_pair(-neighborDistance, neighbor));
			}
		}
	}
	return distance;
}

int main() {
	//정점 개수, 엣지 개수, 시작 정점 번호
	cin >> V >> E >> K;

	V++; //정점 1번부터 시작

	for (int i = 0; i < E; i++) {
		int source, destination, cost;
		cin >> source >> destination >> cost;

		//graph벡터에서 해당하는 '시작 정점' 인덱스에 
		//'도착 정점'과 '가중치' 저장
		graph[source].push_back(make_pair(destination, cost));
	}

	vector<int> result = dijkstra(K, V);

	for (int i = 1; i < V; i++) {
		//출력부분에서 endl 쓰면 시간 초과 발생
		if (result[i] == INF)
			cout << "INF\n";
		else
			cout << result[i] << "\n";
	}
	return 0;
}