#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
/*
	10026. 적록색약
	DFS
*/
using namespace std;
int N, ans = 0;
char map[100][100];
bool visited[100][100];
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };

void dfs(int xx, int yy) {
	visited[xx][yy] = true;
	for (int i = 0; i < 4; i++) {
		int nx = xx + dx[i];
		int ny = yy + dy[i];
		if (nx < 0 || nx >= 100 || ny < 0 || ny >= 100) continue;
		if (!visited[nx][ny] && map[xx][yy] == map[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << " ";

	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'R') map[i][j] = 'G';
		}
	}

	ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0;j < N; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}