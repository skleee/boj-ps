#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
/*
	11058. 크리보드
	Dynamic Programming (long long int 주의)
*/
using namespace std;
int N;
long long int dp[101] = { 0, 1, 2, 3 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 4; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 1;  j < i - 2; j++) {
			dp[i] = max(dp[i], dp[i - (j + 2)] * (j + 1));
		}
	}
	cout << dp[N] << "\n";
	return 0;
}