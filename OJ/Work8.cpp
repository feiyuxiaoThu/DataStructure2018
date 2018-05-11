//二叉搜索树的最小祖先
#include<iostream>
using namespace std;

struct TreeNode {
	int   value;
	TreeNode*  Left;
	TreeNode*  Right;
};

TreeNode* insert(TreeNode* T, int a);
TreeNode* MakeBST(int n);
TreeNode* find(TreeNode* T, int u);
int BST(TreeNode* T, int u, int v);


int main()
{
	TreeNode* T;
	int n, m;

	cin >> n >> m;	

	T = MakeBST(n);

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		cout << BST(T, u, v) << endl;
	}

	return 0;
}

TreeNode* insert(TreeNode* T, int a)
{
	if (!T)
	{
		T = (TreeNode*)malloc(sizeof(struct TreeNode));
		T->value = a;
		T->Left = T->Right = NULL;
	}
	else {
		if (a<T->value)
			T->Left = insert(T->Left, a);
		else
			T->Right = insert(T->Right, a);
	}
	return T;
}

TreeNode* MakeBST(int n)
{
	TreeNode* T = NULL;
	int a;
	while (n--)
	{
		cin >> a;
		T = insert(T, a);
	}
	return T;
}

TreeNode* find(TreeNode* T, int u)
{
	if (!T)
		return 0;
	if (T->value == u)
		return T;
	if (T->value<u)
		return find(T->Right, u);
	if (T->value>u)
		return find(T->Left, u);
}

int LCA(TreeNode* T, int u, int v)
{
	if (u == T->value || v == T->value)
		return T->value;
	if (u>T->value&&v<T->value || u<T->value&&v>T->value)
		return T->value;
	if (u>T->value)
		return LCA(T->Right, u, v);
	if (u<T->value)
		return LCA(T->Left, u, v);
}



int BST(TreeNode* T, int u, int v) {
	TreeNode* U = find(T, u);
	TreeNode* V = find(T, v);
	int left = U->value;
	int right = V->value;
 
	if (left > right) {
		int temp = left;
		left = right;
		right = temp;
	}

	while (1) {
		if (T->value < left) {
			T = T->Right;

		}
		else if (T->value > right) {
			T = T->Left;
		}
		else {
			return T->value;
		}
	}
}

