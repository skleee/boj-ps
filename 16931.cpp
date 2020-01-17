#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
/*
    16931. 겉넓이 구하기
    Simulation
*/
using namespace std;
int map[102][102], N, M, ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	ans += N * M * 2; //Top, Bottom
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			ans += abs(map[i][j] - map[i][j + 1]) + abs(map[i][j] - map[i + 1][j]); // 각 행, 열마다 차이의 절댓값 더함
		}
	}
	cout << ans << "\n";
	return 0;
}