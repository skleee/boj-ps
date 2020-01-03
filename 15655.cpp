#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;
int N, M, number[10], result[10];
bool visited[10];

void go(int locate, int start) {
	if (locate == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = start; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		result[locate] = number[i];
		go(locate + 1, i+1);
		visited[i] = false;
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}
	sort(number, number + N);
	go(0, 0);
	return 0;
}