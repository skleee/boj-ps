#include <iostream>
#include <queue>
#pragma warning(disable:4996)
/*
	15558. 점프게임
	BFS
*/
using namespace std;
int N, K;
char map[2][100001];
bool visited[2][100001], flag = false;

struct point {
	int x, y, time;
};

queue<point> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	q.push({ 0,0,0 });
	visited[0][0] = true;

	while (!q.empty()) {
		point now = q.front();
		q.pop();
		int x = now.x;
		int y = now.y;
		int time = now.time;

		// Move forward
		if (y + 1 == N) {
			flag = true;
		}
		else if (map[x][y + 1] == '1' && !visited[x][y + 1]) {
			visited[x][y + 1] = true;
			q.push({ x, y + 1, time + 1 });
		}

		// Move backward
		if (map[x][y - 1] == '1' && !visited[x][y - 1] && y - 1 > time) {
			visited[x][y - 1] = true;
			q.push({ x, y - 1, time + 1 });
		}

		// Jump (N번칸보다 더 큰 칸으로 이동하면 게임 성공)
		if (y + K >= N) { 
			flag = true;
		}
		else if (map[1 - x][y + K] == '1' && !visited[1 - x][y + K]) {
			visited[1 - x][y + K] = true;
			q.push({ 1 - x, y + K, time + 1 });
		}

	}

	if (flag) cout << 1 << "\n";
	else cout << 0 << "\n";

	return 0;
}