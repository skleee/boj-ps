#include <iostream>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
/*
	1891. 사분면
	Simulation
*/
using namespace std;

long long int d, X, Y, movex, movey;
string num;

//Change number to coordinate
pair<long long int, long long int> numtocoor(long long int idx, long long int n, long long int yy, long long int xx) {
	if (n == 1) {
		return { yy, xx };
	}

	long long int tmp = n / 2;
	long long int p = num[idx] - '0';

	switch (p) {
	case 1:
		return numtocoor(idx + 1, tmp, yy, xx + tmp);
		break;
	case 2:
		return numtocoor(idx + 1, tmp, yy, xx);
		break;
	case 3:
		return numtocoor(idx + 1, tmp, yy + tmp, xx);
		break;
	default:
		return numtocoor(idx + 1, tmp, yy + tmp, xx + tmp);
		break;
	}
}

//Change coordinate to number
string coortonum(string ans, long long int n, long long int yy, long long int xx) {
	if (n == 1) {
		return ans;
	} 

	long long int tmp = n / 2;

	if (X < xx + tmp && Y < yy + tmp) {
		return coortonum(ans + "2", tmp, yy, xx);
	}
	else if (X >= xx + tmp && Y < yy + tmp) {
		return coortonum(ans + "1", tmp, yy, xx + tmp);
	}
	else if (X < xx + tmp && Y >= yy + tmp) {
		return coortonum(ans + "3", tmp, yy + tmp, xx);
	}
	else {
		return coortonum(ans + "4", tmp, yy + tmp, xx + tmp);
	}
}

int main() {
	cin >> d >> num >> movex >> movey;
	long long int digit = 1LL << d;

	pair<long long int, long long int> Pair = numtocoor(0, digit, 0, 0);
	X = Pair.second + movex;
	Y = Pair.first - movey;

	if (0 <= Y && Y < digit && 0 <= X && X < digit) {
		cout << coortonum("", digit, 0, 0) << "\n";
	}
	else {
		cout << "-1\n";
	}
	return 0;
}