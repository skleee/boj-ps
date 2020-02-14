#include <iostream>
#pragma warning(disable:4996)
/*
	2163. 초콜릿 자르기
*/
using namespace std;
int N, M;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	cout << N*M -1 << "\n";
	return 0;
}