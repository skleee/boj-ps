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

vector< pair<int, int>> adj[MAX_V]; 
int dijkstra() {
	vector<int> dist(n+1, INT_MAX);
	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));
	while (!pq.empty())	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost)
			continue;
		for (int i = 0; i < adj[here].size(); i++)	{
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist)	{
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
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