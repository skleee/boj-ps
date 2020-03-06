#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
/*
	11728. 배열합치기
	Sorting
*/
using namespace std;
int N, M;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}