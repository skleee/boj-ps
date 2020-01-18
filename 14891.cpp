#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#pragma warning(disable:4996)
/*
	14891. 톱니바퀴
	Simulation
*/
using namespace std;
int gear[5][9], K, ans = 0;
int topPos[5] = { 0, 0, 0, 0, 0}; //index

void moving(int target, int dir) {
	if (dir == 1) topPos[target] = topPos[target] == 0 ? 7 : topPos[target] - 1; 	//clock
	else topPos[target] = topPos[target] == 7 ? 0 : topPos[target] + 1;	//counterclockwise
}

void go(int num, int dir) {
	bool ableToRotate[5] = { false, };
	vector<pair<int, int>> v;
	for (int i = 1; i < 4; i++) {
		if (gear[i][(topPos[i] + 2) % 8] != gear[i + 1][(topPos[i + 1] + 6) % 8]) ableToRotate[i] = true;
		else ableToRotate[i] = false;
	}
	v.push_back(make_pair(num, dir));
	if (num == 1) {	
		if (ableToRotate[num]) {
			v.push_back(make_pair(num + 1, -dir));
			if (ableToRotate[num + 1]) {
				v.push_back(make_pair(num + 2, dir));
				if (ableToRotate[num + 2]) {
					v.push_back(make_pair(num + 3, -dir));
				}
			}
		}
	}

	else if (num == 2) {
		if (ableToRotate[num-1]) {
			v.push_back(make_pair(num - 1, -dir));
		}
		if (ableToRotate[num]) {
			v.push_back(make_pair(num + 1, -dir));
			if (ableToRotate[num + 1]) {
				v.push_back(make_pair(num + 2, dir));
			}
		}
	}

	else if (num == 3) {
		if (ableToRotate[num]) {
			v.push_back(make_pair(num + 1, -dir));
		}
		if (ableToRotate[num - 1]) {
			v.push_back(make_pair(num - 1, -dir));
			if (ableToRotate[num - 2]) {
				v.push_back(make_pair(num - 2, dir));
			}
		}
	}

	else {
		if (ableToRotate[num - 1]) {
			v.push_back(make_pair(num - 1, -dir));
			if (ableToRotate[num - 2]) {
				v.push_back(make_pair(num - 2, dir));
				if (ableToRotate[num - 3]) {
					v.push_back(make_pair(num - 3, -dir));
				}
			}
		}
	}

	for (int i = 0; i < v.size(); i++) moving(v[i].first, v[i].second);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	for (int i = 1; i <= 4; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			gear[i][j] = s[j] - '0';
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		go(x, y);
	}
	for (int i = 1; i < 5; i++) {
		if(gear[i][topPos[i]]) ans += (int)pow(2, i - 1);
	}
	cout << ans << "\n";
	return 0;
}