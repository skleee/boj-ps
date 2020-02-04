#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
/*
	3052. 나머지
	Array
*/
int main()
{
	int arr[SIZE];
	int remain[43];
	for (int i = 0; i<SIZE; i++) {
		scanf("%d", &arr[i]);
	}

	int rem = 0;
	int cnt = 0;
	for (int i = 0; i<43; i++) {
		remain[i] = 0;
	}
	for (int j = 0; j<SIZE; j++) {
		rem = arr[j] % 42;
		if (remain[rem] == 0) {
			remain[rem] = 1;
			cnt += 1;
		}
	}
	printf("%d", cnt);
	return 0;
}
