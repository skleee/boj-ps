#include <iostream>
#include <queue>
#pragma warning(disable:4996)
/*
	7576. 토마토
	BFS
*/
using namespace std;
int M, N, map[1001][1001];
int checked = 0, day = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;

void bfs() {
	pair<int, int> now;

	while (!q.empty()) {
		int riped = q.size();
		checked += riped;
		if (checked == M * N) {
			cout << day << "\n";
			return;
		}

		for (int i = 0; i < riped;i++) {
			now = q.front();
			q.pop();

			for (int j = 0; j < 4; j++) {
				int xx = now.first + dx[j];
				int yy = now.second + dy[j];

				if (xx < 0 || xx >= M || yy < 0 || yy >= N ) {
					continue;
				}
				if (map[xx][yy] == 0) {
					map[xx][yy] = 1;
					q.push(make_pair(xx, yy));

				}
			}
		}
		day++;
	}
	if (checked != N*M) {
		cout << "-1" << "\n";
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
			}
			else if (map[i][j] == -1) {
				checked++;
			}
		}
	}
	bfs();
	return 0;
}