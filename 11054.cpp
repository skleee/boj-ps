#include <iostream>
#pragma warning(disable:4996)
/*
	11054. 가장 긴 바이토닉 부분 수열
	LIS (Dynamic Programming)
	가장 긴 증가하는 수열 + 가장 긴 감소하는 수열
	i번째 수를 '마지막'으로 하는 증가 수열 / '시작'으로 하는 감소 수열(뒤에서부터 거꾸로)
*/
using namespace std;
int N, A[1000] = { 0 }, dpi[1000] = { 0 }, dpd[1000] = { 0 }, ans = 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N; 
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		dpi[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j] && dpi[i] < dpi[j] + 1) {
				dpi[i] = dpi[j] + 1;
			}
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		dpd[i] = 1;
		for (int j = N-1; j >= i; j--) {
			if (A[i] > A[j] && dpd[i] < dpd[j] + 1) {
				dpd[i] = dpd[j] + 1;
			}
		}
		ans = ans > dpi[i] + dpd[i] - 1 ? ans : dpi[i] + dpd[i] - 1;
	}
	cout << ans << "\n";
	return 0;
}