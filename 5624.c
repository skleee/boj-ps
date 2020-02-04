#include <stdio.h>
#include <stdlib.h>
/*
	5624. 좋은 수
	배열, 구현
*/
#define MAXN 5001
#define M 200000

int n;
int a[MAXN];
int e[2 * M + 1];

extern inline int q(int b) { return e[b + M]; } // query
extern inline void u(int b) { e[b + M] = 1; } // update

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);

	int sol = 0;
	for (int i = 0, ok = 0; i < n; ++i, ok = 0) {
		for (int j = 0; j < i && !ok; ++j)
			ok = q(a[i] - a[j]);
		for (int j = 0; j <= i; ++j)
			u(a[i] + a[j]);
		sol += ok;
	}

	printf("%d\n", sol);
	return 0;
}
