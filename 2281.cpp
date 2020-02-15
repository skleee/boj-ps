#include <iostream>
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)
/*
	2281. 데스노트
	Dynamic Programming
*/
using namespace std;
int N, M, name[1010], dp[1010][1010];

//dp[i][cnt]: i열에 총 cnt개 이름을 썼을 때의 답
int go(int idx, int cnt) {
	if (cnt == N) {
		return 0;
	}
	int ans = dp[idx][cnt];
	if (ans != -1) return ans;

	// 다음 줄로 넘어가는 경우
	int space = M - idx + 2;
	ans = go(name[cnt] + 2, cnt + 1) + space * space;

	// 현재 줄에 이어 쓰는 경우
	if (idx + name[cnt] - 1 <= M) {
		ans = min(ans, go(idx + name[cnt] + 1, cnt + 1));
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> name[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << go(name[0] + 2, 1) << "\n";
	return 0;
}
