#include <iostream>
#include <stack>
#include <string>
#pragma warning(disable:4996)

using namespace std;
int M;
string str;
stack<char> leftst, rightst;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> str >> M;
	for (int i = 0; i < str.length(); i++) {
		leftst.push(str[i]);
	}
	for (int i = 0; i < M; i++) {
		char ipt;
		cin >> ipt;
		if (ipt == 'L') {
			if (leftst.empty()) continue;
			rightst.push(leftst.top());
			leftst.pop();
		}
		else if (ipt == 'D') {
			if (rightst.empty()) continue;
			leftst.push(rightst.top());
			rightst.pop();
		}
		else if (ipt == 'B') {
			if (leftst.empty()) continue;
			leftst.pop();
		}
		else {
			char cc;
			cin >> cc;
			leftst.push(cc);
		}
	}
	while (!leftst.empty()) {
		rightst.push(leftst.top());
		leftst.pop();
	}

	string ans;
	while (!rightst.empty()) {
		ans += rightst.top();
		rightst.pop();
	}
	cout << ans << "\n";
	return 0;
}