#include <iostream>
#include <algorithm>
#include <map>
#pragma warning(disable:4996)
using namespace std;

long long int N, ans;
long long int a[4000], b[4000], c[4000], d[4000];
long long int ab[16000000], cd[16000000];

/*
A B 부분합 저장, C D 부분합 map 저장 & 중복 count
Key: 부분합, Value: count
A B 배열과 Map의 원소 비교
long long int !!!!
복잡도 => Binary Search
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ab[N * i + j] = a[i] + b[j];
			cd[N * i + j] = - (c[i] + d[j]);
		}
	}
	sort(cd, cd + N*N);
	//Binary Search
	ans = 0;
	for (int i = 0; i < N*N; i++) {
		int left = 0, right = N * N;
		int mid;
		while (left < right) {
			mid = (left + right) / 2;
			if (ab[i] > cd[mid]) left = mid + 1;
			else right = mid;
		}
		int low = right;
		left = 0; right = N * N;
		while (left < right) {
			mid = (left + right) / 2;
			if (ab[i] >= cd[mid]) left = mid + 1;
			else right = mid;
		}
		int high = right;
		ans += (long long int)(high - low);
	}


	cout << ans << "\n";
	return 0;
}