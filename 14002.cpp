#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
/*
	14002. 가장 긴 증가하는 부분 수열 4
	LIS (Dynamic Programming)
	수열의 길이와 수열 출력
	이전에 와야 하는 인덱스를 before에 저장
	출력 시 재귀로 차례대로 출력
*/
using namespace std;
int N, endat, A[1000] = { 0 }, dp[1000] = { 0 }, ans = 1, before[1000];
void printAns(int num) {
	if (before[num] == -1) {
		cout << A[num] << " ";
		return;
	}
	printAns(before[num]);
	cout << A[num] << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	// int before[1000] = {-1}; => 초기화 안 되어있었음
	memset(before, -1, sizeof(before)); 
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i] && dp[i] < dp[j] + 1) {
				before[i] = j;
				dp[i] = dp[j] + 1;
			}
		}
		if (ans < dp[i]) {
			ans = dp[i];
			endat = i;
		}
	}
	cout << ans << "\n";
	printAns(endat);
	return 0;
}