#include<iostream>
#include<string>
#pragma warning(disable:4996)

using namespace std;
string str; int ans=1;
int C = 26; int D = 10;

void cntnum() {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'c') {
			if (i < 1) 
				ans *= C;
			else 
				ans = (str[i - 1] == 'c') ? ans * (C - 1) : ans * C;
		}

		else {
			if (i < 1) 
				ans *= D;
			else 
				ans = (str[i - 1] == 'd') ? ans * (D - 1) : ans * D;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	cntnum();
	cout << ans;
	return 0;
}
