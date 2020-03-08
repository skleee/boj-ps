#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 987654321
/*
	1981. 배열에서 이동
	BFS and Binary Search

	배열을 입력받을 때 전체 숫자들의 max와 min을 구한다.
	max-min이 곧 답의 범위이다. (0 <= X <= (max-min))
	Binary Search로 그 범위 내에서의 최대-최소 차이를 찾는다.
	mid값을 매개변수로 넘겨서, 그 숫자 내로 (1,1)에서 (N,N)으로 갈 수 있는지를 확인한다. (BFS)
	만약 갈 수 있다면 (return true), 0 <= X <= mid 범위 안에 답이 있는 것이므로 right = mid - 1을 한다.
	만약 갈 수 없다면 (return false), 그 차이 내로 갈 수 있는 경로가 없다는 것이므로
	mid < X <= right 안에 있는 답을 찾기 위해 left = mid + 1을 한다.
	BFS로 탐색하기 전, 배열의 숫자가 최대-최소 차이 조건에 부합하는지 확인한다.
	각 경우에서 조건에 부합하는 숫자만으로 BFS로 경로를 탐색하고 (n,n)까지 갈 수 있는지 본다.
	결과적으로 Binary Search가 끝났을 때의 mid(=rght+1)가 답이다.
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