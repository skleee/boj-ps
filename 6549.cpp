#include <iostream>
#include <stack>
#include <algorithm>
#include <string.h>
#pragma warning(disable:4996)
/*
	6549. 히스토그램에서 가장 큰 사각형
	Stack
*/
using namespace std;
long long int height[100001], N, ans = 0;

long long int go() {
	stack<long long int> st;
	st.push(-1);
	ans = 0;
	// find left side and right side
	// right side : i-1 / left side : st.top()
	for (long long int i = 0; i < N; i++) {
		while (!st.empty() && height[i] < height[st.top()]) {
			int tmp = st.top();
			st.pop();
			if (!st.empty()) {
				ans = max(ans, height[tmp] * (i - 1 - st.top() ));
			}
		}
		st.push(i);
	}
	// if index remained at stack
	while (!st.empty()) {
		int tmp = st.top();
		st.pop();
		if (!st.empty()) {
			ans = max(ans, height[tmp] * (N - st.top() - 1));
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	while (true) {
		cin >> N;
		if (N == 0) return 0;
		memset(height, 0, sizeof(height));
		for (int i = 0;i < N; i++) {
			cin >> height[i];
		}
		cout << go() << "\n";
	}
	return 0;
}