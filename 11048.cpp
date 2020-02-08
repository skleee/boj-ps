#include <iostream>
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)
/*
	11048. 이동하기
	Dynamic Programming
*/
using namespace std;
int N, M, map[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	memset(map, 0, sizeof(map));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}	
	for (int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			map[i][j] = max(map[i - 1][j], map[i][j - 1]) + map[i][j];
		}
	}
	cout << map[N][M] << "\n";
	return 0;
}