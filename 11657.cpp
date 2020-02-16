#include <iostream>
#include <vector>
#pragma warning(disable:4996)
/*
	11657. 타임머신
	Bellman-Ford Algorithm
*/
using namespace std;
#define INF 987654321

int time[502], N, M;
bool cycle = false;
vector<pair<int, int>> v[502];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;

	// A에서 B로 가는 데에 걸리는 시간 C
	for (int i = 0;i < M;i++) {
		int A, B, C;
		cin >> A >> B >> C;
		v[A].push_back(make_pair(B, C));
	}

	// 초기화
	for (int i = 1;i <= N;i++) {
		time[i] = INF;
	}
	time[1] = 0;

	for (int i = 1;i <= N;i++) {
		// 모든 정점에 대해서 모든 간선을 탐색
		for (int j = 1;j <= N;j++) {
			for (auto &n : v[j]) {
				// 방문되지 않은 지점에서 출발은 SKIP
				// 기존에 구해놨던 n까지의 최단거리보다 j를 거쳐 가는 거리가 작으면 업데이트
				if (time[j] != INF && time[n.first] > n.second + time[j]) {
					time[n.first] = n.second + time[j];
					// N번째 반복문을 돌 때 업데이트 되면 음수 사이클이 있다는 의미
					if (i == N) cycle = true;
				}
			}
		}
	}

	if (cycle) cout << "-1\n";
	else {
		for (int i = 2;i <= N;i++) {
			if (time[i] == INF) cout << "-1\n";
			else cout << time[i] << "\n";
		}
	}
	return 0;
}