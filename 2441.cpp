#include <iostream>
#pragma warning(disable:4996)
/*
	2441. 별찍기4
	출력
*/
using namespace std;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int k = 1; k < i; k++) {
			cout << " ";
		}
		for (int j = N; j >= i; j--) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}