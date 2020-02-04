#include <stdio.h>
/*
	5622. 다이얼
	String
*/

int main() {
	char alpha[16];
	int a = 0;
	int i;
	scanf("%s", alpha);

	for (i = 0; alpha[i] != '\0';i++) {
		if (alpha[i] <= 67 && alpha[i] >= 65)
			a += 3;
		else if (alpha[i] <= 70 && alpha[i] >= 68)
			a += 4;
		else if (alpha[i] <= 73 && alpha[i] >= 71)
			a += 5;
		else if (alpha[i] <= 76 && alpha[i] >= 74)
			a += 6;
		else if (alpha[i] <= 79 && alpha[i] >= 77)
			a += 7;
		else if (alpha[i] <= 83 && alpha[i] >= 80)
			a += 8;
		else if (alpha[i] <= 86 && alpha[i] >= 84)
			a += 9;
		else if (alpha[i] <= 90 && alpha[i] >= 87)
			a += 10;
	}

	printf("%d", a);

	return 0;
}
