#include <iostream>
#pragma warning(disable:4996)
/*
	2523. 별 찍기 13
	출력
*/
using namespace std;
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}		
		cout << "\n";
	}

	for (int i = N - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}