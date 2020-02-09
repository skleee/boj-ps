#include <iostream>
#pragma warning(disable:4996)
/*
	2448. 별찍기 11
	Recursion
*/
using namespace std;
int N;
char map[3100][6200];
char base[3][6] = { "  *  ", " * * ", "*****" };

void go(int n, int yy, int xx) {
	if (n == 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				map[yy + i][xx + j] = base[i][j];
			}
		}
		return;
	}
	go(n / 2, yy + 3 * n / 2, xx);
	go(n / 2, yy, xx + 3 * n / 2);
	go(n / 2, yy + 3 * n / 2, xx + 3 * n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	go(N / 3, 0, 0);
	for (int i = 0 ; i < N ; i++) {
		for (int j = 0 ; j < 2 * N - 1 ; j++) {
			if (map[i][j] == '*') cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
	return 0;
}
