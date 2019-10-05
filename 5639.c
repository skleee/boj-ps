#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct _Node {
	Data data;
	struct _Node* left;
	struct _Node* right;
}TreeNode;


TreeNode* MakeTreeNode(Data data);


void PreorederTraverse(TreeNode* tn);
void InorederTraverse(TreeNode* tn);
void PostorederTraverse(TreeNode* tn);

// BST의 생성 및 초기화
TreeNode*  BSTMakeAndInit(Data data);

// BST를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(TreeNode * bst, Data data);

// BST를 대상으로 데이터 탐색
TreeNode * BSTSearch(TreeNode * bst, Data target);

int main() {
	int n;
	TreeNode* bstRoot;
	scanf("%d", &n);
	bstRoot = BSTMakeAndInit(n);
	while (scanf("%d", &n) != EOF)
	{
		//		scanf("%d", &n);
		if (n == -1)
		{
			break;
		}
		BSTInsert(bstRoot, n);
	}

	PostorederTraverse(bstRoot);

	return 0;
}

TreeNode * MakeTreeNode(Data data)
{
	TreeNode * newnode = (TreeNode*)malloc(sizeof(TreeNode));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}


TreeNode*  BSTMakeAndInit(Data data)
{
	TreeNode * newnode = (TreeNode*)malloc(sizeof(TreeNode));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}


void BSTInsert(TreeNode * bst, Data data)
{

	TreeNode *newNode = MakeTreeNode(data);

	TreeNode* cur = bst;
	while (bst != NULL)
	{
		cur = bst;

		if (bst->data > data)
		{
			bst = bst->left;
		}
		else
		{
			bst = bst->right;
		}

	}
	if (cur->data > data) {
		cur->left = newNode;
	}

	else {
		cur->right = newNode;
	}


}

TreeNode * BSTSearch(TreeNode * bst, Data target)
{
	while (1)
	{

		if (bst->data > target)
		{
			bst = bst->left;
		}
		else if (bst->data == target)
		{
			return bst;
		}
		else if (bst->data < target)
		{
			bst = bst->right;
		}
		else
		{
			return NULL;
		}
	}
}

void PreorederTraverse(TreeNode* tn) {
	if (tn == NULL)return;
	printf("%d \n", tn->data); // 출력위치에 따라서 루트노드 방문 시기가 결정
	PreorederTraverse(tn->left);
	PreorederTraverse(tn->right);
}

void InorederTraverse(TreeNode * tn)
{
	if (tn == NULL)return;
	InorederTraverse(tn->left);
	printf("%d \n", tn->data); // 출력위치에 따라서 루트노드 방문 시기가 결정
	InorederTraverse(tn->right);
}

void PostorederTraverse(TreeNode * tn)
{
	if (tn == NULL)return;
	PostorederTraverse(tn->left);
	PostorederTraverse(tn->right);
	printf("%d \n", tn->data); // 출력위치에 따라서 루트노드 방문 시기가 결정
}