#include <iostream>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)
#define MAXNODE 50001
using namespace std;
/*
	11437. LCA
	Lowest Common Ancestor
*/
vector<int> graph[MAXNODE];
int depth[MAXNODE];
int ac[MAXNODE][20]; //ac[x][y]::x의 2^y번째 조상
int maxlevel;

void initTree(int now, int parent) {
	depth[now] = depth[parent] + 1;
	ac[now][0] = parent;
	maxlevel = (int)floor(log2(MAXNODE));

	for (int i = 1; i <= maxlevel; i++) {
		ac[now][i] = ac[ ac[now][i - 1] ][i - 1];
	}

	// dfs 알고리즘으로 정점 이어줌
	int len = graph[now].size();
	for (int i = 0; i < len; i++) {
		int there = graph[now][i];
		if (there != parent)
			initTree(there, now);
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n, m;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	depth[0] = -1;
	initTree(1, 0);

	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b]) {
				swap(a, b);
			}

			for (int i = maxlevel; i >= 0; i--) {
				// b의 2^i번째 조상의 depth가 a의 depth보다 같거나 크면 (더 밑에 있으면) 
				if (depth[a] <= depth[ac[b][i]]) {
					b = ac[b][i];
				}
			}
		}

		int lca = a;
		if (a != b) {
			for (int i = maxlevel; i >= 0; i--) {
				if (ac[a][i] != ac[b][i]) {
					a = ac[a][i];
					b = ac[b][i];
				}
				lca = ac[a][i];
			}
		}
		cout << lca << "\n";
	}

	return 0;
}