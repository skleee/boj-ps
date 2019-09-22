#include <iostream>
#pragma warning(disable:4996)

using namespace std;
int N, ans;
int num[] = { 1, 5, 10, 50 };
bool check[1001] = {};

void go(int cur, int cnt, int sum) {
	if (cur == N) {
		if (!check[sum]) {
			check[sum] = true;
			ans++;
		}
		return;
	}
	for (int i = cnt; i < 4; i++) {
		go(cur + 1, i, sum + num[i]);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	go(0, 0, 0);
	cout << ans;
	return 0;
}