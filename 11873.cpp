#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#pragma warning(disable:4996)
/*
	11873. 최대 직사각형
	Histogram using stack
*/
using namespace std;
long long int N, M, map[1005];

long long int go() {
	stack<long long int> st;
	st.push(-1);
	long long int tmpans = 0;
	// Find left side and right side
	// left: st.top(), right: i-1
	for (int i = 0; i < M; i++) {
		while (!st.empty() && map[i] < map[st.top()]) {
			long long int tmp = st.top();
			st.pop();
			if (!st.empty()) {
				tmpans = max(tmpans, map[tmp] * (i - 1 - st.top()));
			}
		}
		st.push(i);
	}
	// If index remained at stack
	while (!st.empty()) {
		long long int tmp = st.top();
		st.pop();
		if (!st.empty()) {
			tmpans = max(tmpans, map[tmp] * (M - st.top() - 1));
		}
	}
	return tmpans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0) {
			return 0;
		}
		long long int ans = -1;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				long long int tmp;
				cin >> tmp;
				if (i > 0 && tmp == 0) map[j] = 0;
				else map[j] += tmp;
			}
			ans = max(ans, go());
		}
		cout << ans << "\n";
	}
	return 0;
}