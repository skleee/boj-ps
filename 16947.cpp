#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
/*
    16947. 서울 지하철 2호선
    BFS: 거리 카운트
	DFS: 사이클 찾기
*/
using namespace std;
int N, check[3001], dist[3001];
vector<int> map[3001];
queue<int> q;

int go(int x, int p) {
	// 0~n-1: found cycle and start index
	// -1: not found cycle
	// -2: found cycle and not included
	if (check[x]) {
		return x;
	}
	check[x] = 1;
	for (int i = 0; i < map[x].size(); i++) {
		int y = map[x][i];
		if (y == p) continue; // 서로 지목
		
		int ret = go(y, x);
		if (ret == -2) return -2;

		if (ret >= 0) {
			check[x] = 2;
			if (x == ret) return -2;
			else return ret;
		}
	}
	return -1;
}

void bfs() {
	for (int i = 1; i <= N; i++) {
		if (check[i] == 2) {
			dist[i] = 0;
			q.push(i);
		}	
	}
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < map[tmp].size(); i++) {
			int x = map[tmp][i];
			if (check[x] == 2) continue;
			check[x] = 2;
			dist[x] = dist[tmp] + 1;
			q.push(x);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	go(1, -1);
	bfs();
	for (int i = 1; i <= N; i++) {
		cout << dist[i] << " ";
	}
	cout << "\n";
	return 0;
}