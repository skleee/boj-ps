#include <iostream>
#pragma warning(disable:4996)
using namespace std;
/*
	11053. 가장 긴 증가하는 부분 수열
	LIS (Dynamic Programming)

*/
int N, A[1000] = { 0 }, dp[1000] = { 0 }, ans = 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		ans = ans > dp[i] ? ans : dp[i];
	}
	cout << ans << "\n";
	return 0;
}