#include <iostream>
#pragma warning(disable:4996)
/*
	1107. 리모컨
	브루트포스, 수학
*/
using namespace std;
int N, M, ans;
bool failed[10] = { false, };

bool check(int x) {
	if (x == 0 && failed[0]) return false;
	while (x > 0) {
		if (failed[x % 10]) return false;
		x /= 10;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		failed[tmp] = true;
	}

	if (N == 100) {
		cout << 0 << "\n";
		return 0;
	}
	// Move only with +/-
	ans = abs(N - 100); 
	// Move to certain number and use +/-
	for (int i = 0; i < 1000000; i++) { 
		if (check(i)) {			
			int tmp = abs(N - i);
			if (i == 0) tmp += 1;
			else {
				int num = i;
				while (num > 0) {
					tmp++;
					num /= 10;
				}
			}
			ans = ans > tmp ? tmp : ans;
		}
	}
	cout << ans << "\n";
	return 0;
}