#include <iostream>
#include <vector>
#pragma warning(disable:4996)
/*
	17103. 골드바흐 파티션
	수학 (sieve of eratosthenes)
*/
using namespace std;
int T;
bool prime[1000001];
vector<int> pv;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	for (int i = 2; i < 1000000; i++) {
		if (!prime[i]) {
			pv.push_back(i);
			for (int j = 2; j * i < 1000000; j++) {
				prime[j * i] = true;
			}
		} 
	}
	cin >> T;
	while (T--) {
		int tmp, ans = 0;
		cin >> tmp;
		for (int i = 0; pv[i] < tmp; i++) {
			if (tmp - pv[i] >= pv[i] && !prime[tmp - pv[i]]) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}