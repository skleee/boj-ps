#include <stdio.h>
#pragma warning(disable:4996)

int dir[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
int N, djcnt, jibcnt;
int map[25][25];
int home[25];

void sorting(void) {
	for (int i = 0; i < djcnt; i++) {
		for (int j = 0; j < djcnt - 1; j++) {
			if (home[j] > home[j + 1]) {
				int temp = home[j];
				home[j] = home[j + 1];
				home[j + 1] = temp;
			}
		}
	}

}

void dfs(int a, int b) {
	int xx, yy;
	map[a][b] = 0;
	jibcnt++;

	//�����¿� Ȯ��
	for (int i = 0; i < 4; i++) {
		xx = a + dir[i][0];
		yy = b + dir[i][1];
		//���� �Ѿ���� Ȯ��
		if (xx < 0 || xx > N - 1 || yy < 0 || yy > N - 1)
			continue;
		if (map[xx][yy] == 1)
			dfs(xx, yy);
	}
}

int main(void) {
	scanf("%d", &N);

	//���� �Է� �ޱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]); //�ϳ��� ����
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0) {
				dfs(i, j);
				home[djcnt] = jibcnt; //���� �� �� �� ����
				djcnt++; //���� �� ī��Ʈ
				jibcnt = 0; //���� �� �� �� �ʱ�ȭ
			}
		}
	}

	//��������
	sorting();

	printf("%d\n", djcnt);
	for (int i = 0; i < djcnt; i++)
		printf("%d\n", home[i]);

	return 0;
}

