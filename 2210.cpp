#include <iostream>
#include <set>
#pragma warning(disable:4996)

using namespace std;
int map[5][5] = {0};
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

set<int> s;

void dfs(int xx, int yy, int cnt, int num) {
	if (cnt == 6) {
		s.insert(num);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int sx = xx + dx[i];
		int sy = yy + dy[i];
		if (sx < 0 || sx >= 5 || sy < 0 || sy >= 5) continue;
		dfs(sx, sy, cnt + 1, num * 10 + map[sx][sy]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 1, map[i][j]);
		}
	}
	cout << s.size() << "\n";
	return 0;
}