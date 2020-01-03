#include <iostream>
#pragma warning(disable:4996)

using namespace std;
int N, M;
int result[10];

void go(int locate) {
	if (locate == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		result[locate] = i;
		go(locate + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	go(0);
	return 0;
}