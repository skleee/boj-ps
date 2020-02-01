#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
/*
	13397. 구간나누기
	Binary Search
*/
using namespace std;
int N, M, arr[5000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}
	int l = 0, r = 10000, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		int cnt = 1, minn = arr[0], maxx = arr[0];
		for (int i = 1; i < N; i++) {
			minn = min(minn, arr[i]);
			maxx = max(maxx, arr[i]);
			if (mid < maxx - minn) {
				minn = arr[i];
				maxx = arr[i];
				cnt++;
			}
		}
		if (cnt <= M) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans << "\n";

	return 0;
}