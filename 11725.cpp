#include <iostream>
#include <vector>

/*
	11725. 트리의 부모 찾기
	트리, DFS
*/
using namespace std;
int N, parents[100001];
bool visited[100001] = { false, };
vector<int> v[100001];

void go(int idx, int locate) {
	visited[idx] = true;
	parents[idx] = locate;

	for (int i = 0; i < v[idx].size(); i++) {
		if (!visited[v[idx][i]]) {
			go(v[idx][i], idx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	go(1, 0);
	for (int i = 2; i <= N; i++) {
		cout << parents[i] << "\n";
	}
	return 0;
}