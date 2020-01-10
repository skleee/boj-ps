#include <string>
#include <iostream>
#include <queue>
#include <set>
#pragma warning(disable:4996)

using namespace std;
long long int S, T;
bool flag = false;
string ans = "";
queue<pair<long long int, string>> q;
set<long long int> visited;

void BFS() {
	q.push(make_pair(S, ""));
	visited.insert(S);
	while (!q.empty()) {
		long long int now = q.front().first;
		string nowOp = q.front().second;
		if (now == T) {
			ans = nowOp;
			flag = true;
			return;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			pair<long long int, string> newpair;
			if (i == 0) {
				newpair = { now*now, "*" };
			}
			else if (i == 1) {
				newpair = { now+now, "+" };
			}
			else if (i == 2) {
				newpair = { now-now, "-" };
			}
			else {
				newpair = { now/now, "/" };
			}
			//연산 값이 1보다 작거나 이미 계산해서 visited에 들어있는 값이면 continue
			if (newpair.first < 1) continue;
			if (visited.find(newpair.first) != visited.end()) continue;
			
			visited.insert(newpair.first);
			q.push(make_pair(newpair.first, nowOp + newpair.second));
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> S >> T;
	if (S == T) {
		cout << 0 << "\n";
		return 0;
	}
	BFS();
	if (flag) cout << ans << "\n";
	else cout << -1 << "\n";
	return 0;
}