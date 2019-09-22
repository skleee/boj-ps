#include <iostream>
#include <vector>
#pragma warning(disable:4996)

using namespace std;
int N, maxeng;
vector <int> v(N);

void go(int eng) {
	if (v.size() == 2) {
		if (eng > maxeng) maxeng = eng;
		return;
	}

	int tmp;
	for (int i = 1; i < v.size() - 1; i++) {
		int cur = v[i];
		tmp = v[i - 1] * v[i + 1];
		v.erase(v.begin() + i);
		go(eng + tmp);
		v.insert(v.begin() + i, cur);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 0;i < N;i++) {
		int nn;
		cin >> nn;
		v.push_back(nn);
	}
	go(0);
	cout << maxeng;
	return 0;
}