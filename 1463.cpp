#include <iostream>
#pragma warning(disable:4996)

using namespace std;
int N;
int arr[1000001] = { 0, };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	arr[1] = 0;
	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0 && arr[i] > arr[i / 2] + 1) {
			arr[i] = arr[i / 2] + 1;
		}
		if (i % 3 == 0 && arr[i] > arr[i / 3] + 1) {
			arr[i] = arr[i / 3] + 1;
		}
	}
	cout << arr[N];

	return 0;
}