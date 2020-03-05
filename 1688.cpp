#include <iostream>
#include <vector>
#define MAXVAL 1000000001
#pragma warning(disable:4996)
/*
	1688. 지민이의 테러
	Geometry
	Inside-Polygon test (Ray casting algorithm)
*/
using namespace std;

struct Point {
	long long x, y;
};
vector<Point> v;
int N;

// struct Point의 x, y 좌표를 비교하는 함수. (기준 1: x 좌표, 기준 2: y 좌표)
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

// 점이 내부에 있는지 확인하는 함수
bool isInside(long long xx, long long yy) {
	int cnt = 0;
	Point tmp = { xx, yy }; // 검사하려는 점

	for (int i = 0; i < N; i++) {
		Point v1 = v[i];
		Point v2 = v[(i + 1) % N];
		Point end = { MAXVAL,  yy + 1 };
		if (isIntersect(v1, v2, tmp, end)) 	cnt++;
		/*
			다각형의 꼭짓점은 항상 시계방향 또는 시계 반대방향 순으로 주어지기 때문에 차례대로 검사한다.
			v[0]&v[1], v[1]&v[2], v[2]&v[3] ... v[N-1]&v[0] 형태로 검사하기 위해 mod 연산으로 v2의 인덱스를 구한다.
			다각형의 내부, 외부를 판별하기 위해 검사하는 점과 다각형 바깥의 점을 하나 찍어 선을 긋는다.
			이때 '다각형 바깥에 있는 점'의 x좌표는 좌표 범위보다 1 큰 값으로, 입력값으로 존재할 수 없는 값으로 한다.
			y좌표는 검사할 점의 y좌표+1을 한 값으로 해서, 절대 꼭짓점과 겹치거나 직선이 변과 겹치게 되는 경우가 없게 한다.
			그은 선이 다각형의 변과 만나는 횟수가 홀수이면 내부, 짝수이면 외부에 있는 것이다.
			선분 교차 여부는 CCW로 판별한다. CCW 함수 내에서 일직선인 경우 false가 반환되도록 하여, 검사할 점이 다각형의 변 위에 있는 경우가 고려된다.
		*/
	}
	return cnt % 2;
}

// 같은 좌표의 꼭짓점이 있는지 확인하는 함수
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

		// 먼저 다각형 꼭짓점과 겹치는지 확인. 겹친다면 경계 위에 있는 것이므로 1 반환
		if (isPoint(xx, yy)) cout << "1\n";
		// 내부에 있는지 확인
		else {	
			cout << isInside(xx, yy) << "\n";
		}
	}
	return 0;
}