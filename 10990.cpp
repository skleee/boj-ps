#include <iostream>
#pragma warning(disable:4996)
/*
	10990. 별 찍기 - 15
	출력
*/
using namespace std;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N - i; j++) {
			cout << " ";
		}
		cout << "*";
		if (i == 1) {
			cout << "\n";
			continue;
		} 
		else {
			for (int j = 1; j <= 2 * (i - 1) - 1; j++) {
				cout << " ";
			}
			cout << "*\n";
		}
	}

	return 0;
}