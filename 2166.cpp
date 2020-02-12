#include <iostream>
#include <algorithm>
#include <math.h>
/*
	2166. 다각형의 면적
	Geometry - CCW
*/
using namespace std;
long long point[10000][2];
int N;
long long ans = 0;
long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	return (x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> point[i][0] >> point[i][1];
	}
	for (int i = 2; i < N; i++) {
		ans += ccw(point[0][0], point[0][1], point[i - 1][0], point[i - 1][1], point[i][0], point[i][1]);
	}
	//소수점 아래 둘째 자리에서 반올림하여 첫째 자리까지 출력
	ans = abs(ans);
	cout << ans / 2 << ".";
	if (ans % 2 == 0) cout << "0";
	else cout << "5";
	return 0;
}