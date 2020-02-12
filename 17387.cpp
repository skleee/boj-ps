#include <iostream>
#pragma warning(disable:4996)
/*
	17387. 선분 교차 2
	Geometry
    두 선분이 일직선인 경우 고려
*/
using namespace std;
struct Point {
	long long x, y;
};

bool comparePoint(Point a, Point b) {
	return a.x < b.x || (!(a.x > b.x) && a.y < b.y);
}

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	long long tmp = x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3;
	if (tmp > 0) return 1;
	else if (tmp < 0) return -1;
	return 0;
}

bool isIntersect(Point l11, Point l12, Point l21, Point l22) {
	int case1 = ccw(l11.x, l11.y, l12.x, l12.y, l21.x, l21.y) * ccw(l11.x, l11.y, l12.x, l12.y, l22.x, l22.y);
	int case2 = ccw(l21.x, l21.y, l22.x, l22.y, l11.x, l11.y) * ccw(l21.x, l21.y, l22.x, l22.y, l12.x, l12.y);
	
	// 두 직선이 일직선일 경우 판단
	if (case1 == 0 && case2 == 0) {
		if (!comparePoint(l11, l12)) swap(l11, l12);
		if (!comparePoint(l21, l22)) swap(l21, l22);
		if (comparePoint(l12, l21) || comparePoint(l22, l11)) return false;
		else return true;
	}
	
	if (case1 > 0 || case2 > 0) return false;
	else return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	Point p1, p2, p3, p4;
	cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
	cout << isIntersect(p1, p2, p3, p4) << "\n";
	return 0;
}