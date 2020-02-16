#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> // INT_MAX
#include <cstdio>
#pragma warning(disable:4996)
/*
    1916. 최소비용 구하기
    Dijkstra Algorithm (Priority Queue)
*/
#define MAX_V 1001 

using namespace std;
int n, m, src, dst;

// 그래프의 인접 리스트. (연결된 정점 번호, 간선 가중치) 쌍을 담아야 한다.
vector< pair<int, int>> adj[MAX_V]; // 정점의 최대 개수 MAX_V

int dijkstra() {
	// n+1만큼 배열을 INT_MAX로 초기화
	vector<int> dist(n+1, INT_MAX);
	dist[src] = 0; // 시작점은 0으로 초기화

	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src)); // 시작점을 처음으로 우선순위 큐에 삽입

	while (!pq.empty())	{
		// 우선순위 큐에 음의 가중치로 들어가 있으니 양으로 바꾸어준다.
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		// 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸것을 무시한다.
		if (dist[here] < cost)
			continue;

		// 인접한 정점들을 모두 검사.
		for (int i = 0; i < adj[here].size(); i++)	{
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			// 더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다.
			// dist 벡터에는 시작점 -> there 위치까지의 최단 거리가 담겨있다.
			if (dist[there] > nextDist)	{
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
				/*
				여기서 -로 넣는 이유?
				priority_queue STL은 기본적으로 가장 큰 원소가 위로 가도록 큐를 구성
				따라서 거리의 부호를 바꿔서 거리가 작은 정점부터 꺼내지도록 하기 위함
				*/
			}
		}
	}
	return dist[dst];
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;

	int from, to, val;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> val;
		adj[from].push_back(make_pair(to, val));
	}

	cin >> src >> dst;
	cout << dijkstra() << "\n";

	return 0;
}