#include <iostream>
#pragma warning(disable:4996)

using namespace std;
int N, M;
long long int A;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M >> A;
	A %= M;
	for (int i = 1; i < N; i++) {
		long long int B;
		cin >> B;
		A = (A*B) % M;
	}
	cout << A;
	return 0;
}