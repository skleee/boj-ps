#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
/*
	10942. 팰린드롬?
	Dynamic Programming
*/
using namespace std;
int N, num[2001], M, dp[2001][2001];

int go(int i, int j) {
	if (i == j) {
		return dp[i][j] = 1; // one letter
	}
	else if (i + 1 == j) { // two letters
		if (num[i] == num[j]) return dp[i][j] = 1;
		else return dp[i][j] = 0;
	}

	if (dp[i][j] >= 0) { // dp answer is already filled
		return dp[i][j];
	}

	// two ends are not same
	if (num[i] != num[j]) { 
		dp[i][j] = 0;
	}
	// same -> recursion
	else { 
		dp[i][j] = go(i + 1, j - 1);
	}
	return dp[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	cin >> M;
	memset(dp, -1, sizeof(dp));
	while (M--) {
		int S, E;
		cin >> S >> E;
		cout << go(S, E) << "\n";
	}
	/*for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	return 0;
}