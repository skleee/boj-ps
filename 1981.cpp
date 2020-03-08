#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 987654321
#pragma warning(disable:4996)
/*
	1981. 배열에서 이동
	BFS and Binary Search
*/
using namespace std;
bool visited[101][101];
int N, map[101][101], minn = INF, maxx = 0;
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

bool bfs(int diff) {	
	for (int st = minn; st <= maxx; st++) { // minn ~ maxx 범위
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= N; i++) { // 파라미터로 받은 최대 최소 차이가 가능한지 확인
			for (int j = 1; j <= N; j++) {
				if (map[i][j] < st) {
					visited[i][j] = true;
				}
				else if (map[i][j] >= st && map[i][j] <= st + diff) {
					visited[i][j] = false;
				}
				else {
					visited[i][j] = true;
				}
			}
		}
		if (visited[1][1]) continue; // 처음 숫자가 범위에 속하지 않는 경우도 고려!!!!!

		// BFS
		queue<pair<int, int>> q;
		visited[1][1] = true;
		q.push({ 1,1 });
		while (!q.empty()) {
			int nx = q.front().first, ny = q.front().second;
			q.pop();

			// 탈출조건:: (n,n)에 도착
			if (nx == N && ny == N) {
				return 1;
			}
			
			for (int i = 0; i < 4; i++) {
				int xx = nx + dx[i], yy = ny + dy[i];
				if (!visited[xx][yy] && xx > 0 && xx <= N && yy > 0 && yy <= N) {
					visited[xx][yy] = true;
					q.push({ xx, yy });
				}
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			minn = minn > map[i][j] ? map[i][j] : minn;
			maxx = maxx < map[i][j] ? map[i][j] : maxx;
		}
	}

	// Binary Search
	int lft = 0, rght = maxx - minn;
	while (lft <= rght) {
		int mid = (lft + rght) / 2;
		if (bfs(mid)) rght = mid - 1;
		else lft = mid + 1;
	}
	cout << rght + 1 << "\n"; // rght = mid - 1 이기 때문에 실제 답은 rght + 1
	return 0;
}