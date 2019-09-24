#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 20000 + 1;
const int INF = 987654321;

int V, E, K;
vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int start, int vertex) {
	vector<int> distance(vertex, INF);//���� ������ŭ �Ÿ� �ʱ�ȭ
	distance[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cost = -pq.top().first;//�Ÿ��� ���� �������� ������ ���� ��ȣ ����
		int curVertex = pq.top().second;
		pq.pop();

		//�̹� �� ���� ��� �Ѿ��.
		if (distance[curVertex] < cost)
			continue;

		for (int i = 0; i < graph[curVertex].size(); i++) {
			int neighbor = graph[curVertex][i].first;
			int neighborDistance = cost + graph[curVertex][i].second;

			//�ּ� ��� �߰� �� ������Ʈ
			if (distance[neighbor] > neighborDistance) {
				distance[neighbor] = neighborDistance;
				//�Ÿ��� ���� �������� ������ ���� ��ȣ ����
				pq.push(make_pair(-neighborDistance, neighbor));
			}
		}
	}
	return distance;
}

int main() {
	//���� ����, ���� ����, ���� ���� ��ȣ
	cin >> V >> E >> K;

	V++; //���� 1������ ����

	for (int i = 0; i < E; i++) {
		int source, destination, cost;
		cin >> source >> destination >> cost;

		//graph���Ϳ��� �ش��ϴ� '���� ����' �ε����� 
		//'���� ����'�� '����ġ' ����
		graph[source].push_back(make_pair(destination, cost));
	}

	vector<int> result = dijkstra(K, V);

	for (int i = 1; i < V; i++) {
		//��ºκп��� endl ���� �ð� �ʰ� �߻�
		if (result[i] == INF)
			cout << "INF\n";
		else
			cout << result[i] << "\n";
	}
	return 0;
}