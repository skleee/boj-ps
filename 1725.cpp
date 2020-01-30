#include <iostream>
#include <stack>
#include <algorithm>
#pragma warning(disable:4996)
/*
	1725. 히스토그램
	stack (6549와 동일)
*/
using namespace std;
long long int N, ans = 0, height[1000001];
stack<long long int> st;

void go() {
	st.push(-1);
	for (long long int i = 0; i < N; i++) {
		while (!st.empty() && height[i] < height[st.top()]) {
			int tmp = st.top();
			st.pop();
			if (!st.empty()) {
				ans = ans > height[tmp] * (i - 1 - st.top()) ? ans : height[tmp] * (i - 1 - st.top());
			}
		}
		st.push(i);
	}
	while (!st.empty()) {
		int tmp = st.top();
		st.pop();
		if (!st.empty()) {
			ans = ans > height[tmp] * (N - 1 - st.top()) ? ans : height[tmp] * (N - 1 - st.top());
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> height[i];
	}
	go();
	return 0;
}