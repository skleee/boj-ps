#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int N, wine[10001], dp[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> wine[i];
	}
	dp[1] = wine[1]; dp[2] = wine[1] + wine[2];
	for (int i = 3; i <= N; i++) {
		dp[i] = max({ dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i], dp[i - 1] });
	}
	cout << dp[N];
	return 0;
}