#include <iostream>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int N, M, ans=10000, jibcnt = 0, chkcnt = 0;
bool visited[20];
vector<pair<int, int>> house, chicken, result;

void go(int start, int locate) {
	if (locate == M) {
		int dstsum = 0;
		for (int i = 0; i < house.size(); i++) {
			int eachmin = 10000000;
			for (int j = 0; j < result.size(); j++) {
				int tmp = abs(result[j].first - house[i].first) + abs(result[j].second - house[i].second);
				eachmin = eachmin > tmp ? tmp : eachmin;
			}
			dstsum += eachmin;
		}
		ans = ans > dstsum ? dstsum : ans;
		return;
	}
	for (int i = start; i < chicken.size(); i++) {
		if (visited[i]) continue;
		visited[i] = true;
		result.push_back(make_pair(chicken[i].first, chicken[i].second));
		go(i+1, locate + 1);
		visited[i] = false;
		result.pop_back(); //******pop을 해야 새로운 걸 넣음
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;			
			if (tmp == 1) house.push_back(make_pair(i, j));
			if (tmp == 2) chicken.push_back(make_pair(i, j));		
		}
	}
	go(0, 0);
	cout << ans << "\n";
	return 0;
}