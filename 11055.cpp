#include <iostream>
#pragma warning(disable:4996)
/*
	11055. 가장 큰 증가하는 부분 수열
	LIS (Dynamic Programming)
	수열의 합이 가장 큰 증가 부분 수열의 합
*/
using namespace std;
int N, A[1000] = { 0 }, dp[1000] = { 0 }, ans = 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		dp[i] = A[i];
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i] && dp[i] < dp[j] + A[i]) {
				dp[i] = dp[j] + A[i];
			}
		}
		ans = ans > dp[i] ? ans : dp[i];
	}
	cout << ans << "\n";
	return 0;
}