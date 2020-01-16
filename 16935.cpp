#include <iostream>
#include <algorithm>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;
int N, M, R, op, map[300][300], tmp[300][300];

void rotate(int op) {
	switch (op) {
	case 1:
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < M; j++) {
				swap(map[i][j], map[N - i - 1][j]);
			}
		}
		break;
	case 2:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M / 2; j++) {
				swap(map[i][j], map[i][M - j - 1]);
			}
		}
		break;
	case 3:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmp[i][j] = map[i][j];
			}
		}
		memset(map, 0, sizeof(map));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[j][N - 1 - i] = tmp[i][j];
			}
		}
		swap(N, M);
		break;
	case 4:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmp[i][j] = map[i][j];
			}
		}
		memset(map, 0, sizeof(map));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[M - 1 - j][i] = tmp[i][j];
			}
		}
		swap(N, M);
		break;
	case 5:
		memset(tmp, 0, sizeof(tmp));
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < M / 2; j++) {
				tmp[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < M / 2; j++) {
				map[i][j] = map[i + N / 2][j]; // move 4 to 1
				map[i + N / 2][j] = map[i + N / 2][j + M / 2]; // move 3 to 4
				map[i + N / 2][j + M / 2] = map[i][j + M / 2]; // move 2 to 3
				map[i][j + M / 2] = tmp[i][j]; // move 1 to 2
			}
		}
		break;
	case 6:
		memset(tmp, 0, sizeof(tmp));
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < M / 2; j++) {
				tmp[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < M / 2; j++) {
				map[i][j] = map[i][j + M / 2]; // move 1 to 4
				map[i][j + M / 2] = map[i + N / 2][j + M / 2]; // move 4 to 3
				map[i + N / 2][j + M / 2] = map[i + N / 2][j]; // move 3 to 2
				map[i + N / 2][j] = tmp[i][j]; // move 2 to 1
			}
		}
		break;
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
	for (int i = 0; i < R; i++) {
		cin >> op;
		rotate(op);	
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	return 0;
}