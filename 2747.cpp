#include <iostream>
#pragma warning(disable:4996)
/*
	2747. 피보나치
	Dynamic programming
*/
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int S; 
	long long int d[92] = {0,1};
	cin >> S;
	if (S == 0 || S == 1) {
		cout << S << "\n";
	}
	else {
		for (int i = 2; i <= S; i++) {
			d[i] = d[i - 2] + d[i - 1];
		}
		cout << d[S] << "\n";
	}
	return 0;
}