#include <iostream>
/*
	11758. CCW
	Geometry
*/
using namespace std;
int p1x, p1y, p2x, p2y, p3x, p3y;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int tmp = x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3;
	if (tmp > 0) return 1;
	else if (tmp < 0) return -1;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;
	cout << ccw(p1x, p1y, p2x, p2y, p3x, p3y) << "\n";
	return 0;
}