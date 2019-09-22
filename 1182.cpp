#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;
int N, S, cnt, arry[21];

//자리는 다 있고 더하는 거 O/X로 재귀
void getsum(int idx, int partsum) {
	if (idx == N) {
		if (partsum == S) {
			cnt++;
		}
		return;
	}
	idx++;
	getsum(idx, partsum + arry[idx - 1]);
	getsum(idx, partsum);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> S;

	for (int i = 0; i < N;i++) {
		cin >> arry[i];
	}

	getsum(0, 0);
	if (S == 0) cnt--;
	cout << cnt;
	return 0;
}

