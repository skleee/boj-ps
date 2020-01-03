#include <iostream>
#pragma warning(disable:4996)

using namespace std;
int N, M, result[10];
bool visited[10];

void go(int locate, int start) {
	if (locate == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = start; i <= N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		result[locate] = i;
		go(locate + 1, i + 1);
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	go(0, 1);
	return 0;
}