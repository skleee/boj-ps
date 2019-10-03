#include <iostream>
#pragma warning(disable:4996)

using namespace std;
int N;
long long arr[91] = { 0,1, };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout << arr[N];
	return 0;
}