#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#pragma warning(disable:4996)

/* 
    나3곱2: 수학
    정렬 기준을 (1) 3의 인수가 많은 순 (2) 2의 인수가 적은 순으로 함
    long long int 때문에 오답
    문제에서 num의 범위가 <= 10^18
*/

using namespace std;
long long int N, num;
vector<tuple<long long int, long long int, long long int>> v;

//tuple sorting하기 (https://www.geeksforgeeks.org/sorting-vector-tuple-c-ascending-order/)
bool sorting(const tuple< long long int, long long int, long long int> xx, const tuple<long long int, long long int, long long int> yy) {
	long long int sec1, thr1, sec2, thr2;
	tie(ignore, sec1, thr1) = xx; tie(ignore, sec2, thr2)=yy;
	if (sec1 == sec2) {
		return thr1 < thr2;
	}
	return sec1 > sec2;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		long long int tmp = num;
		long long int cnt1 = 0;
		long long int cnt2 = 0;
		while (tmp%3==0) {
			tmp /= 3;
			cnt1++;
		}

		tmp = num;
		while (tmp%2==0) {
			tmp /= 2;
			cnt2++;
		}
		v.push_back(make_tuple(num, cnt1, cnt2));
	}
	sort(v.begin(), v.end(), sorting);

	for (int i = 0; i < N; i++) {
		cout << get<0>(v[i]) << " ";
	}
	return 0;
}