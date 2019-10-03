#include <iostream>
#pragma warning(disable:4996)

using namespace std;
int nn;
int arr[1001] = { 1,1,0, };
//D[n] = 2*D[n-1] + D[n-2] 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> nn;
	for (int i = 2; i <= nn; i++) {
		arr[i] = (arr[i - 2] * 2 + arr[i - 1]) % 10007;
	}
	cout << arr[nn];
	return 0;
}