#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
/*
    16927. 배열돌리기2
*/
using namespace std;
int N, M, R, map[300][300];

void rotate() {
	int group = min(M, N) / 2; // 그룹의 개수
	for (int k = 0; k < group; k++) {
		int rtcnt = R % ((N + M - 2 - 4 * k) * 2); // 그룹 안 숫자의 개수
		while (rtcnt--) {
			int tmp = map[k][k];
			for (int i = k + 1; i < M - k; i++) {
				map[k][i - 1] = map[k][i]; // top
			}
			for (int i = k + 1; i < N - k; i++) {
				map[i - 1][M - k - 1] = map[i][M - k - 1]; // right
			}
			for (int i = M - k - 2; i >= k; i--) {
				map[N - k - 1][i + 1] = map[N - k - 1][i]; // bottom
			}
			for (int i = N - k - 2; i > k; i--) {
				map[i + 1][k] = map[i][k]; // left
			}
			map[k + 1][k] = tmp;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			map[i][j] = a;
		}
	}

	rotate();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	return 0;
}