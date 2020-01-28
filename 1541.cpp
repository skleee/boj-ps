#include <iostream>
#include <string>
#pragma warning(disable:4996)
/*
	1541. 잃어버린 괄호
	그리디알고리즘
*/
using namespace std;
bool flag = false;
string tmp = "";
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> str;
	int ans = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			if (!flag) {
				ans += stoi(tmp);
			} 
			else {
				ans -= stoi(tmp);
			}
			tmp = "";
			if (str[i] == '-') flag = true;
		}
		else {
			tmp += str[i];
			if (i == str.length() - 1) {
				if (!flag) {
					ans += stoi(tmp);
				}
				else {
					ans -= stoi(tmp);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}