#include <iostream>
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)
/*
	1389. 케빈 베이컨의 6단계 법칙
	Floyd-Warshall Algorithm
*/
using namespace std;
int map[101][101], N, M;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j || map[i][k] == 0 || map[k][j] == 0) {
					continue;
				}
				if (map[i][j] == 0) map[i][j] = map[i][k] + map[k][j];
				else map[i][j] = min(map[i][j], map[i][k] + map[k][j]);				
			}
		}
	}

	pair<int, int> ans = { 0, 10000000 };
	for (int i = 1; i <= N; i++) {
		int tmp = 0;
		for (int j = 1; j <= N; j++) {
			tmp += map[i][j];
		}
		if (tmp < ans.second) ans = { i, tmp };
	}
	cout << ans.first << "\n";
	return 0;
}