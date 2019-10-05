#include <iostream>
#pragma warning(disable:4996)
using namespace std;
long long arr[100001][4] = { {0,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,1,1,1}, };
int tc, nn, test[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);	
	cin >> tc;
	for (int i = 4; i <= 100000;i++) {
		arr[i][1] = (arr[i - 1][2] + arr[i - 1][3]) % 1000000009;
		arr[i][2] = (arr[i - 2][1] + arr[i - 2][3]) % 1000000009;
		arr[i][3] = (arr[i - 3][2] + arr[i - 3][1]) % 1000000009;
	}
	while (tc--) {
		cin >> nn;
		cout << (arr[nn][1] + arr[nn][2] + arr[nn][3]) % 1000000009 << "\n";
	}
	return 0;
}