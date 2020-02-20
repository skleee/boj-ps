#include <iostream>
#include <cstring>
#include <limits.h>
#include <algorithm>
#pragma warning(disable:4996)
/*
	11049. 행렬 곱셈 순서
	Dynamic Programming
*/
using namespace std;
int N, m[501][2], dp[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	memset(m, 0, sizeof(m));
	cin >> N;	

	for (int i = 1; i <= N; i++) {
		cin >> m[i][0] >> m[i][1];
	}
	for (int i = 1; i <= N ; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) dp[i][i] = 0;
			else dp[i][j] = INT_MAX;
		}
	}

	for (int h = 1; h <= N; h++) { // 간격
		for (int i = 0; i + h <= N; i++) { // 시작점
			int j = i + h; // 끝점
			for (int k = i; k < j; k++) { // 중간
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + m[i][0] * m[k][1] * m[j][1]);
			}
		}
	}

	cout << dp[1][N] << "\n";
	return 0;
}