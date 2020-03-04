#include <iostream>
#pragma warning(disable:4996)
#define mod 1000000009
/*
	16195. 1, 2, 3 ¥ı«œ±‚ 9
	Dynamic Programming
*/
using namespace std;
int tc, n, m, D[1001][1001] = {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	D[1][1] = D[2][1] = D[3][1] = D[3][3] = D[2][2] = 1;
	D[3][2] = 2;
	for (int i = 4; i <= 1000; i++) {
		for (int j = 2; j <= i; j++) {
			D[i][j] = ((D[i - 1][j - 1] + D[i - 2][j - 1]) % mod + D[i - 3][j - 1]) % mod;
		}
	}
	cin >> tc;
	while (tc--) {
		cin >> n >> m;	
		int ans = 0;
		for (int j = 1; j <= m; j++) {
			ans += D[n][j];
			ans %= mod;
		}
		cout << ans << "\n";
	}
	return 0;
}