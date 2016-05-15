#include <stdlib.h>
#include <stdio.h>

//½¨Á¢¶þ²æÊ÷
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
	int leftLength = rootInOrder - startInOrder;
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