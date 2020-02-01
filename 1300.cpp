#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
/*
    1300. K번째 수
    Binary Search
*/
using namespace std;
int N, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> K;

	int ll = 1,rr = K, ans;
	while (ll <= rr){
		long long num = 0;
		int mid = (ll + rr) / 2;
		
		for (int i = 1; i <= N; i++) {
			num += min(mid / i, N);
		}
		if (num < K) {
			ll = mid + 1;
		}
		else {
			ans = mid;
			rr = mid - 1;
		}
	}
	cout << ans << "\n";
	return 0;
}