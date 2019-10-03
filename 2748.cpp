#include <iostream>
#pragma warning(disable:4996)

using namespace std;
/*long long arr[91] = {0,};
int fibonacci(int N) {
	if (N <= 1) {
		return N;
	}
	else {
		if (arr[N] > 0) {
			return arr[N];
		}
		arr[N] = fibonacci(N - 1) + fibonacci(N - 2);
		return arr[N];
	}
}*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int S; cin >> S;
//	cout << fibonacci(S);
	long long d[92];
	d[0] = 0; d[1] = 1;
	if (S == 0 || S == 1) {
		cout << S;
	}
	else {
		for (int i = 2; i <= S; i++) {
			d[i] = d[i - 2] + d[i - 1];
		}
		cout << d[S];
	}
	return 0;
}