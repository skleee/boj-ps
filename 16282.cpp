#include <iostream>
#pragma warning(disable:4996)

using namespace std;
long long n, maxx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for (long long i = 1 ; i <= n ; i++) {
		maxx = (i + 1LL)*(1LL << (i + 1)) - 1;
		if (maxx >= n) {
			cout << i;
			break;
		}
	}
	return 0;
}