#include <iostream>
#include <vector>
#pragma warning(disable:4996)

using namespace std;
int N, L, R, X, prob[20];
int ans = 0;
bool visited[20];
vector<int> v;

void go(int index, int locate, int tmpsum) {
	if (locate >= 2) {
		//선택 다 하고나서 min, max, sum 구함
		int minn = 999999999;
		int maxx = -999999999;
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += prob[v[i]];
			minn = minn > prob[v[i]] ? prob[v[i]] : minn;
			maxx = maxx > prob[v[i]] ? maxx : prob[v[i]];
		}
		if ((sum >= L) && (sum <= R) && (maxx - minn >= X)) {
			ans++;
		}
	}
	for (int i = index; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		v.push_back(i);
		go(i, locate + 1, tmpsum + prob[i]);
		v.pop_back();
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++) {
		cin >> prob[i];
	}
	go(0, 0, 0);
	cout << ans << "\n";
	return 0;
}