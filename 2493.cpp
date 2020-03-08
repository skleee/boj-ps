#include <iostream>
#include <vector>
#include <stack>
#pragma warning(disable:4996)
/*
	2493. 탑
	Stack
*/
using namespace std;
int N, tmp;
stack<pair<int, int>> st;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &tmp);
		while (!st.empty()) {
			if (st.top().second > tmp) {
				printf("%d ", st.top().first);
				break;
			}
			st.pop();
		}
		if (st.empty()) printf("0 ");
		st.push(make_pair(i, tmp));
	}
	return 0;
}