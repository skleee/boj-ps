#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
	int data;
	struct _node *next;
} Node;

typedef struct _listStack
{
	Node *top;
} LLQueue;


void StackInit(LLQueue * pstack)
{
	pstack->top = NULL;
}

int SIsEmpty(LLQueue *pstack)
{
	if (pstack->top == NULL) return 1;
	else return 0;
}

void SPush(LLQueue *pstack, int data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->next = pstack->top;
	newNode->data = data;
	pstack->top = newNode;
}

int SPop(LLQueue *pstack)
{
	int item;
	Node * temp = pstack->top;

	if (pstack->top == NULL) {
		return -1;
	}

	else {
		item = temp->data;
		pstack->top = temp->next;
		free(temp);
		return item;
	}
}

int SPeek(LLQueue *pstack)
{
	if (pstack->top == NULL) {
		return -1;
	}
	else {
		return(pstack->top->data);
	}
}

int Size(LLQueue *pstack)
{
	Node *temp = pstack->top;
	int cnt = 0;
	if (pstack->top != NULL) {
		while (temp) {
			temp = temp->next;
			cnt++;
		}
	}
	return cnt;
}


int main()
{
	int N, num;
	char str[13];

	LLQueue stack;
	StackInit(&stack);

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", str);

		if (!strcmp(str, "push")) {
			scanf("%d", &num);
			SPush(&stack, num);
		}
		else if (!strcmp(str, "pop")) {
			printf("%d\n", SPop(&stack));
		}
		else if (!strcmp(str, "empty")) {
			printf("%d\n", SIsEmpty(&stack));
		}
		else if (!strcmp(str, "size")) {
			printf("%d\n", Size(&stack));
		}
		else if (!strcmp(str, "top")) {
			printf("%d\n", SPeek(&stack));
		}
	}

	return 0;
}
