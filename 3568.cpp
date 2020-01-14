#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
/*
	3568. iSharp
	Simulation
*/
using namespace std;
string base;
vector<string> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> base;
	while (true) {
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
		if (tmp.back() == ';') break;
	}
	for (int i = 0; i < v.size(); i++) {
		string chr, ans;
		//chr = v[i].substr(0, 1);
		ans = base;

		for (int j = v[i].length() - 1; j >= 0; j--) {
			if (v[i][j] == ',' || v[i][j] == ';') continue;
			else if (v[i][j] == '[') ans += ']';
			else if (v[i][j] == ']') ans += '[';
			else if (v[i][j] == '*' || v[i][j] == '&') ans += v[i][j];
			else if (isalpha(v[i][j])) {
				chr = v[i][j] + chr;
			}
		}
		ans += ' ' + chr + ';';
		cout << ans << "\n";
	}
	return 0;

}