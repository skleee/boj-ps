#include <iostream>
#pragma warning(disable:4996)
/*
	2447. 별찍기10
	Recursion
*/
using namespace std;
int N;

void go(int i, int j, int nn) {
	if ((i / nn) % 3 == 1 && (j / nn) % 3 == 1) {
		cout << " ";
	}
	else {
		if (nn / 3 == 0) cout << "*";
		else go(i, j, nn / 3);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			go(i, j, N/3);
		}
		cout << "\n";
	}
	return 0;
}