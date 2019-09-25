#include <stdio.h>
#pragma warning(disable:4996)

int N;
int parent[50];

void deleteNode(int del) {
	int j;
	parent[del] = -2;
	for (j = 0; j < N; j++) {
		if (parent[j] == del) {
			deleteNode(j);
		}
	}
}

int countLeaf() {
	int cnt = 0;
	int flag = 0;
	for (int i = 0; i < N; i++) {
		flag = 0; //flag초기화

				  //삭제되었거나(-2거나), 자식이 있으면 flag 
		for (int j = 0; j < N; j++) {
			if (parent[i] < -1 || parent[j] == i) {
				flag = 1;
			}
		}

		//어느것도 아니면(flag==0이면) cnt
		if (flag == 0) cnt++;
	}
	return cnt;
}


int main()
{
	int pp;
	int deleted;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &pp);
		parent[i] = pp;
	}

	scanf("%d", &deleted);
	deleteNode(deleted);

	printf("%d", countLeaf());
	return 0;
}