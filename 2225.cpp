#include <iostream>
#pragma warning(disable:4996)
#define modu 1000000000
using namespace std;
int N, K;
long long int memo[202][202] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i <= N; i++) {
		memo[1][i] = 1;
	}
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int l = 0; l <= j; l++) {
				memo[i][j] += memo[i - 1][j - l];
				memo[i][j] %= modu;
			}
		}
	}
	cout << memo[K][N] << "\n";
	return 0;
}