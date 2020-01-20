#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
/*
	9019.DSLR
	BFS ("4연산"과 유사)
*/
using namespace std;
int tc, A, B;
bool visited[10000];

void bfs() {
	memset(visited, false, sizeof(visited));
	queue<pair<int, string>> q;

	visited[A] = true;
	q.push(make_pair(A, ""));

	while (!q.empty()) {
		int now = q.front().first;
		string nowop = q.front().second;
		q.pop();

		if (now == B) {
			cout << nowop << "\n";
			return;
		}

		int tmp = (now * 2) % 10000;
		if (!visited[tmp]) {
			visited[tmp] = true;
			q.push(make_pair(tmp, nowop + "D"));
		}

		tmp = now < 1 ? 9999 : now - 1;
		if (!visited[tmp]) {
			visited[tmp] = true;
			q.push(make_pair(tmp, nowop + "S"));
		}

		tmp = (now % 1000) * 10 + now / 1000;
		if (!visited[tmp]) {
			visited[tmp] = true;
			q.push(make_pair(tmp, nowop + "L"));
		}

		tmp = now / 10 + now % 10 * 1000;
		if (!visited[tmp]) {
			visited[tmp] = true;
			q.push(make_pair(tmp, nowop + "R"));
		}

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> tc;
	while (tc--) {
		cin >> A >> B;
		bfs();
	}
	return 0;
}