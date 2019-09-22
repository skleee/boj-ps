#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
#define MAX 4000000
using namespace std;
int N, check[MAX + 1] = {}, ans = 0, tmp = 0, lft = 0, rght = 0;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;

	for (int i = 2; i*i <= N; i++) {
		if (!check[i]) {
			for (int j = i * i; j <= N; j += i) {
				check[j] = 1;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (!check[i]) {
			v.push_back(i);
		}
	}
	while (1) {
		if (tmp > N) {
			tmp -= v[lft++];
		}
		else if (rght == v.size()) {
			break;
		}
		else {
			tmp += v[rght++];
		}

		if (tmp == N) ans++;
	}
	cout << ans;
	return 0;
}