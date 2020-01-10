#include <iostream>
#include <queue>
#pragma warning(disable:4996)

using namespace std;
int T, L;
int xx[] = { 1, 2,  2,  1, -1, -2, -2, -1 };
int yy[] = { 2, 1, -1, -2, -2, -1,  1,  2 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> T;
	while (T--) {
		int map[300][300] = {0};
		bool visited[300][300] = {false};
		queue<pair<int, int>> q;
		int ans = 0;
		int mx, my, dx, dy;
		cin >> L >> mx >> my >> dx >> dy;
		visited[mx][my] = true;
		q.push(make_pair(mx, my));

		while (!q.empty()) {
			int nowx = q.front().first; 
			int nowy = q.front().second;
			q.pop();

			if (nowx == dx && nowy == dy) {
				cout << map[nowx][nowy] << "\n";
				cout << ans << '\n';
				break;
			}

			for (int i = 0; i < 8; i++) {
				int tx = nowx + xx[i];
				int ty = nowy + yy[i];

				if (tx >= 0 && tx < L && ty >= 0 && ty < L) {
					if (!visited[tx][ty]) {
						visited[tx][ty] = true;
						map[tx][ty] = map[nowx][nowy] + 1;
						q.push(make_pair(tx, ty));
					}
				}
				
			}
		}
		
	}
	return 0;
}