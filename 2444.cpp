#include <iostream>
#pragma warning(disable:4996)
/*
	2444. 별찍기7
	출력
*/
using namespace std;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 1; i < N; i++) {
		for (int k = 1; k <= N - i; k++) {
			cout << " ";
		}
		for (int j = 1; j <= 2 * i - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = 0; i <= N; i++) {
		for (int k = 0; k < i; k++) {
			cout << " ";
		}
		for (int j = 0; j < 2 * (N - i) - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}