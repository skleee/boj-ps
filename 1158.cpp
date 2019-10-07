#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}Node;

Node* CreateNode(int data, Node* next)
{
	Node* NewNode;
	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = data;
	NewNode->next = next;
	return (NewNode);
}

void InsertLast(Node** head, Node* node)
{
	if (*head == NULL)
	{
		*head = node;
		node->next = node;
	}
	else
	{
		node->next = (*head)->next;
		(*head)->next = node;
		*head = node;
	}
}

void RemoveNode(Node** head, Node* p)
{
	Node* deleted;
	deleted = p->next;
	p->next = deleted->next;

	if (deleted == (*head)->next)
		(*head)->next = deleted->next;
	printf("%d", deleted->data);
	free(deleted);
}

void display(Node* head, int n, int k)
{
	Node* p;
	int i, j;
	if (head == NULL) return;
	p = head;
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < k - 1; i++)
		{
			p = p->next;
		}
		RemoveNode(&head, p);
		if (j != n - 1)
			printf(",");
		if (j != n - 1)
			printf(" ");
	}

}
int main(void)
{
	int N = 0, K = 0;
	int i;
	Node* plist = NULL;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++)
	{
		InsertLast(&plist, CreateNode(i, NULL));
	}
	printf("<");
	display(plist, N, K);
	printf(">");
	return 0;
}
