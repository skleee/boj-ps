#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	scanf("%d", &num);
	int way[1001];

	for (int i = 0; i<num; i++) {
		scanf("%d", &way[i]);
	}

	int max = 0;
	int height = 0;

	for (int j = 1; j<num; j++) {
		if (way[j - 1]<way[j]) {
			height += way[j] - way[j - 1];
			if (max<height)
				max = height;
		}
		else
			height = 0;
	}
	printf("%d", max);
	return 0;
}
