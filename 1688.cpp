#include <iostream>
#include <vector>
#define MAXVAL 1000000001
#pragma warning(disable:4996)
/*
	1688. 지민이의 테러
	Geometry
*/
using namespace std;

struct Point {
	long long x, y;
};
vector<Point> v;
int N;

bool comparePoint(Point a, Point b) {
	return a.x < b.x || (!(a.x > b.x) && a.y < b.y);
}

long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	long long tmp = x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3;
	if (tmp > 0) return 1;
	else if (tmp < 0) return -1;
	return 0;
}

bool isIntersect(Point l11, Point l12, Point l21, Point l22) {
	int case1 = ccw(l11.x, l11.y, l12.x, l12.y, l21.x, l21.y) * ccw(l11.x, l11.y, l12.x, l12.y, l22.x, l22.y);
	int case2 = ccw(l21.x, l21.y, l22.x, l22.y, l11.x, l11.y) * ccw(l21.x, l21.y, l22.x, l22.y, l12.x, l12.y);

	if (case1 == 0 && case2 == 0) {
		if (!comparePoint(l11, l12)) swap(l11, l12);
		if (!comparePoint(l21, l22)) swap(l21, l22);
		if (comparePoint(l12, l21) || comparePoint(l22, l11)) return false; 	// 일직선인 경우 false return
		else return true;
	}

	if (case1 > 0 || case2 > 0) return false;
	else return true;
}

bool isInside(long long xx, long long yy) {
	int cnt = 0;
	Point tmp = { xx, yy };

	for (int i = 0; i < N; i++) {
		Point v1 = v[i];
		Point v2 = v[(i + 1) % N];
		Point end = { MAXVAL,  yy + 1 }; // 다른 정점과 겹치지 않도록
	
		if (isIntersect(v1, v2, tmp, end)) 	cnt++;
	}
	return cnt % 2;
}

bool isPoint(long long xx, long long yy) {
	for (int i = 0; i < N; i++) {
		if (v[i].x == xx && v[i].y == yy) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	Point point;
	for (int i = 0; i < N; i++) {
		cin >> point.x >> point.y;
		v.push_back(point);
	}	

	for (int i = 0; i < 3; i++) {
		int xx, yy;
		cin >> xx >> yy;
		if (N < 3) {
			cout << "0\n";
			continue;
		}

		if (isPoint(xx, yy)) cout << "1\n";
		else {	
			cout << isInside(xx, yy) << "\n";
		}
	}
	return 0;
}