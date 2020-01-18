#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
#define MAXNUM 1001
/*
	14501. 퇴사
	Dynamic Programming
*/
using namespace std;
int N, t[MAXNUM], p[MAXNUM], dp[MAXNUM];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> t[i] >> p[i];
	}
	for (int i = N; i >= 1; i--) { 
		if (i + t[i] > N + 1) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + 1], dp[i + t[i]] + p[i]);
		}
	}
	cout << dp[1] << "\n";
	return 0;
}