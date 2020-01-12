#include <iostream>
#include <queue>
#include <cstring>
#pragma warning(disable:4996)
/*
    16928 뱀과 사다리 게임
    BFS
*/
using namespace std;
int N, M;
int step[101] = { 0, }, map[101];
queue<int> q;

void bfs() {
	map[1] = 0;
	q.push(1);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int next = now + i;

			if (next > 100) continue;

			if (step[next]) next = step[next];

			if (map[next] < 0) {
				map[next] = map[now] + 1;
				q.push(next);
			}
		}
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		int x, y;
		cin >> x >> y;
		step[x] = y;
	}

	memset(map, -1, sizeof(map));
	bfs();
	cout << map[100] << '\n';
	return 0;
}