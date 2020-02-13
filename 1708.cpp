#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
/*
	1708. 볼록껍질
	Geometry
	Convex Hull Algorithm (Graham's Scan Algorithm)
*/
using namespace std;
int N;
vector<pair<int, int>> v;
pair<int, int> base;

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	long long tmp = x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3;
	if (tmp > 0) return 1;
	else if (tmp < 0) return -1;
	return 0;
}

long long distance(pair<int, int> aa, pair<int, int> bb) {
	return (aa.first - bb.first)*(aa.first - bb.first) + (aa.second - bb.second)*(aa.second - bb.second);

}

// 각도 정렬: 나머지 점들 k에 대해 CCW(base, target, k) 모두 반시계 (+)
bool sorting(pair<int, int> aa, pair<int, int> bb) {
	if (ccw(base.first, base.second, aa.first, aa.second, bb.first, bb.second) > 0) return true;
	else if (ccw(base.first, base.second, aa.first, aa.second, bb.first, bb.second) < 0) return false;
	// 일직선 위일 경우 거리 비교. 먼 점이 뒤로 오게 정렬
	else {
		if (distance(base, aa) < distance(base, bb)) return true;
		else return false;
	}
}

// Y 비교 -> X 비교
bool compare(pair<int, int> aa, pair<int, int> bb) {
	if (aa.second < bb.second || (!(aa.second > bb.second) && aa.first <= bb.first)) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end(), compare);
	base = v[0];
	sort(v.begin() + 1, v.end(), sorting);
	
	vector<pair<int, int>> st;
	for (int i = 0; i < N; i++) {
		while (st.size() >= 2 && ccw(st[st.size() - 2].first, st[st.size() - 2].second, st[st.size() - 1].first, st[st.size() - 1].second, v[i].first, v[i].second) <= 0) {
			st.pop_back();
		}
		st.push_back(v[i]);
	}
	cout << st.size() << "\n";
	return 0;
}