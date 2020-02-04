#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	5397. 키로거
	Linked list, Simulation
*/
char arr[1000001];
int i = 0;

typedef struct _Node
{
	char data;
	struct _Node *next;
	struct _Node *prev;
}Node;

typedef struct _dblinkedlist
{
	Node *head;
	Node *tail;
	Node *cur;
}DBLinkedList;

void initList(DBLinkedList *plist)
{

	Node *headDummy = (Node*)malloc(sizeof(Node));
	Node *tailDummy = (Node*)malloc(sizeof(Node));

	headDummy->next = tailDummy;
	tailDummy->prev = headDummy;

	headDummy->prev = NULL;
	tailDummy->next = NULL;
	headDummy->data = NULL;
	headDummy->data = NULL;

	plist->head = headDummy;
	plist->tail = tailDummy;
	plist->cur = headDummy;
}

void operate(DBLinkedList *plist) {
	if (arr[i] == '<') {
		if (plist->cur != plist->head) {
			plist->cur = plist->cur->prev;
		}
	}

	else if (arr[i] == '>') {
		if (plist->cur->next != plist->tail) {
			plist->cur = plist->cur->next;
		}
	}

	else if (arr[i] == '-') {
		if (plist->cur->data != NULL) {
			Node *tmp = plist->cur;
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			plist->cur = tmp->prev;
			free(tmp);
		}
	}
	else {
		Node *newnode = (Node*)malloc(sizeof(Node));
		newnode->data = arr[i];

		newnode->prev = plist->cur;
		newnode->next = plist->cur->next;

		plist->cur->next->prev = newnode;
		plist->cur->next = newnode;
		plist->cur = newnode;
	}
	i++;
}

void print(DBLinkedList *plist)
{
	plist->cur = plist->head->next;

	while (plist->cur != plist->tail)
	{
		printf("%c", plist->cur->data);
		plist->cur = plist->cur->next;
	}
	printf("\n");
}

void freedblist(DBLinkedList *plist)
{
	Node *tmp;
	plist->cur = plist->head;
	while (plist->cur != plist->tail)
	{
		tmp = plist->cur;
		plist->cur = plist->cur->next;
		free(tmp);
	}
	free(plist->tail);
}

int main()
{
	int N;
	int leng;
	scanf("%d", &N);
	for (int t = 0; t<N; t++)
	{
		DBLinkedList list;
		scanf("%s", arr);
		leng = strlen(arr);

		initList(&list);

		i = 0;
		for (int j = 0; j < leng; j++) {
			operate(&list);
		}
		print(&list);
		freedblist(&list);

	}
	return 0;
}
