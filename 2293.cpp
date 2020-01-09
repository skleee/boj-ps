#include <iostream>
#pragma warning(disable:4996)
/*
    2293. 동전 1
    Dynamic programming
    중복이 안 되는 점화식
*/
using namespace std;
int N, K, arr[1001] = { 0, }, memo[10001] = { 1, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}
	for (int i = 0; i < N; i++) {
		for (int j = arr[i]; j <= K; j++) {
			memo[j] += memo[j - arr[i]];
		}
	}
	cout << memo[K] << "\n";
	return 0;
}