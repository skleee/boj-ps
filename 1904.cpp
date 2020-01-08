#include <iostream>
#pragma warning(disable:4996)

using namespace std;
int N, memo[1000002] = { 0,1,2, };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 3; i <= N; i++) {
		memo[i] = (memo[i - 1] + memo[i - 2]) % 15746;
	}
	cout << (memo[N] % 15746) << "\n";
	return 0;
}