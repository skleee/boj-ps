#include <iostream>
#pragma warning(disable:4996)
/*
브루트포스: 입력받는 인덱스가 1부터 시작한다면 계산할 때 0 포함 안 하도록 확인
범위 주의
*/
using namespace std;
int N, M, cnt = 0, answer[3];
int combi[202][202] = {0,};
bool visited[202] = { false, };

void go(int index, int locate) {
	if (locate == 3) {
		cnt++;
		return;
	}
	for (int i = index; i < N; i++) {
		if (visited[i]) continue;
		if (locate == 1 && combi[i+1][answer[locate - 1]]) continue;
		if (locate == 2 && (combi[i+1][answer[locate - 1]] || combi[i+1][answer[locate - 2]])) continue;
		visited[i] = true;
		answer[locate] = i+1;
		go(i, locate + 1);
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int xx, yy;
		cin >> xx >> yy;
		combi[xx][yy] = 1;
		combi[yy][xx] = 1;
	}
	go(0, 0);
	cout << cnt << "\n";
	return 0;
}