#include <iostream>
#include <algorithm>
#include <cstring>
/*
	2281. 데스노트
	Dynamic Programming
*/
using namespace std;
int N, M, dp[1001][1001], name[1001];
//dp[i][cnt]: i열에 총 cnt개 이름을 썼을 때의 답

int go(int idx, int cnt) {
	if (cnt == N) {
		return 0;
	}

	// 열 꽉 찰 때
	if (idx >= M) {
		return go(name[cnt] + 1, cnt + 1) + (idx == M ? 1 : 0);
	}

	// dp 값 있을 때
	int &ans = dp[idx][cnt];
	if (ans != -1) return ans;
	// 다음 줄로 넘어가는 경우
	int space = M - idx + 1;
	ans = space * space + go(name[cnt] + 1, cnt + 1);
	// 현재 줄에 이어 쓰는 경우
	if (idx + name[cnt] <= M) {
		ans = min(ans, go(idx + name[cnt] + 1, cnt + 1));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> name[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << go(name[0] + 1, 1) << "\n";
	return 0;
}