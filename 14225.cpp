#include <iostream>
#include <algorithm>
#include <set>
#pragma warning(disable:4996)

using namespace std;
int N, arry[21], minnum;

set<int> sumset;

void getsum(int idx, int psum) {
	if (idx == N) {
		sumset.insert(psum);
		return;
	}
	idx++;
	getsum(idx, psum);
	getsum(idx, psum + arry[idx - 1]);
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arry[i];
	}
	getsum(0, 0);

	set<int>::iterator iter;
	for (int i = 1; i <= sumset.size(); i++) {
		iter = sumset.find(i);
		if (iter == sumset.end()) {
			minnum = i;
			break;
		}
	}
	cout << minnum;
	return 0;
}

