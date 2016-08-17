/*
输入某二叉树的前序遍历和中序遍历的结果，
请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
则重建二叉树并返回。
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	int m_nValue;
	struct Node* lChild, *rChild;
}BinaryTreeNode;

BinaryTreeNode* build(int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder){
	int rootValue = *startPreOrder;
	BinaryTreeNode* root = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	root->m_nValue = rootValue;
	root->lChild = root->rChild = NULL;
	if (startPreOrder == endPreOrder)
	{
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
			return root;
		else
		{
			perror("Invalid input");
			return NULL;
		}
	}
	int* rootInOrder = startInOrder;
	while (rootInOrder <= endInOrder && *rootInOrder != rootValue)
		++rootInOrder;
	if (rootInOrder == endInOrder && *rootInOrder != rootValue)
	{
		perror("Invalid input");
		return NULL;
	}
	int leftLength = rootInOrder - startInOrder;//求左子树的长度
	int* leftPreOrderEnd = leftLength + startPreOrder;
	if (leftLength > 0)
	{
		root->lChild = build(startPreOrder + 1, leftPreOrderEnd, startInOrder, rootInOrder - 1);
	}
	if (leftLength < endPreOrder - startPreOrder)
	{
		root->rChild = build(leftPreOrderEnd + 1, endPreOrder, rootInOrder + 1, endInOrder);
	}
	return root;
}
BinaryTreeNode* buildTree(int* preorder, int* inorder, int length){
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;
	else
		return build(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

void print(BinaryTreeNode* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->m_nValue);
	print(root->lChild);
	print(root->rChild);
}
void Test(){
	int a[7] = {1,2,4,5,3,6,7};
	int b[7] = {4,2,5,1,6,3,7};
	BinaryTreeNode* c = buildTree(a,b,7);
	print(c);
}
