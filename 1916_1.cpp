#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#pragma warning(disable:4996)
#define INF 999999999
/*
	1916. 최소비용 구하기
	Dijkstra Algorithm 인접행렬(벡터)
*/
using namespace std;
int n, m, src, dst, dist[1001];
bool visited[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	vector<vector<int>> W(n + 1, vector<int>(n + 1, INF));
	memset(visited, false, sizeof(visited));
	for (int i = 0; i <= n; i++) {
		W[i][i] = 0;
		dist[i] = INF;
	}
	for (int i = 0; i < m; i++)	{
		int from, to, cost;
		cin >> from >> to >> cost;
		W[from][to] = min(W[from][to], cost);
	}
	cin >> src >> dst;	

	dist[src] = 0;
	for (int k = 0; k < n - 1; k++) {
		// dist의 값이 가장 작은 노드 v를 선택
		int mindist = INF + 1;
		int x = -1;
		for (int i = 1; i <= n; i++) {
			if (visited[i] == false && mindist > dist[i]) {
				mindist = dist[i];
				x = i;
			}
		}
		// v와 연결된 모든 정점 검사
		visited[x] = true;
		for (int i = 1; i <= n; i++) {
			dist[i] = min(dist[i], dist[x] + W[x][i]);
		}
	}
	cout << dist[dst] << "\n";
	return 0;
}