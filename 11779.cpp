#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> 
#include <cstdio>
#include <stack>
#include <cstring>
#pragma warning(disable:4996)
/*
    11779. 최소비용구하기2
    Dijkstra Algorithm
*/
#define MAX_V 1001 

using namespace std;
int n, m, src, dst;

vector< pair<int, int>> adj[MAX_V]; 
int bf[1001];

int dijkstra() {
	vector<int> dist(1001, INT_MAX);
	dist[src] = 0; 
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src)); 
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost)
			continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i].first;
			int nextCost = cost + adj[here][i].second;
			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push(make_pair(-nextCost, next));
				bf[next] = here;
			}
		}
	}
	return dist[dst];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	memset(bf, -1, sizeof(bf));
	int from, to, val;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> val;
		adj[from].push_back(make_pair(to, val));
	}

	cin >> src >> dst;

	cout << dijkstra() << "\n";

	stack<int> st;
	int x = dst;
	while (x != -1) {
		st.push(x);
		x = bf[x];
	}
	cout << st.size() << "\n";
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}