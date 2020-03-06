#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
/*
	10815. 숫자카드
	Binary search
*/
using namespace std;
int N, M;
vector<int> v;

bool go(int tmp) {
	int lft = 0, rght = v.size(); 
	while (lft <= rght) {
		int mid = (lft + rght) / 2;
		if (tmp < v[mid]) {
			rght = mid - 1;
		}
		else if (tmp > v[mid]) {
			lft = mid + 1;
		}
		else {
			return true;
		}
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		cout << go(num) << " ";
	}
	return 0;
}