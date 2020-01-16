#include <iostream>
#pragma warning(disable:4996)
/*
	1991. 트리 순회
    Preorder, Inorder, Postorder
*/
using namespace std;
int N, tree[26][2];
void preorder(int node) {
	if (node == -1) return;
	cout << char(node + 'A');
	preorder(tree[node][0]);
	preorder(tree[node][1]);
}
void inorder(int node) {
	if (node == -1) return;
	inorder(tree[node][0]);
	cout << char(node + 'A');
	inorder(tree[node][1]);
}
void postorder(int node) {
	if (node == -1) return;
	postorder(tree[node][0]);
	postorder(tree[node][1]);
	cout << char(node + 'A');
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		tree[root - 'A'][0] = left == '.' ? -1 : left - 'A';
		tree[root - 'A'][1] = right == '.' ? -1 : right - 'A';
	}
	preorder(0); cout << "\n";
	inorder(0); cout << "\n";
	postorder(0); cout << "\n";
	return 0;
}