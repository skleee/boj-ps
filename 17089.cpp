#include <iostream>
#pragma warning(disable:4996)

using namespace std;
int N, M, result[5], ans=-1;
bool visited[4002] = { false, };
int relate[4002][4002] = { 0, };

void go(int start, int locate) {
	if (locate == 3) {
		int cnt = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 1; j <= N; j++) {
				if (relate[result[i]][j]) cnt++;
			}
		}
		if (relate[result[0]][result[1]]) cnt -= 2;
		if (relate[result[1]][result[2]]) cnt -= 2;
		if (relate[result[0]][result[2]]) cnt -= 2;
		
		if (ans == -1 || ans > cnt) ans = cnt;
		
		return;
	}

	for (int i = start; i <= N; i++) {
		if (visited[i]) continue;
		if (locate == 1 && !relate[result[locate-1]][i+1]) continue;
		if (locate == 2 && (!relate[result[locate - 1]][i+1] || !relate[result[locate - 2]][i+1])) continue;
		visited[i] = true;
		result[locate] = i+1;
		go(i + 1, locate + 1);
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int nn, mm;
		cin >> nn >> mm;
		relate[nn][mm] = 1;
		relate[mm][nn] = 1;
	}
	go(0, 0);
	cout << ans << "\n";
	return 0;
}