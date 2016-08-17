//求树的镜像，即树的左右孩子交换
#include <stdlib.h>
#include <stdio.h>
#include <stack>

using namespace std;
struct BinaryTreeNode{
	int m_Value;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
//只能建设满二叉树
BinaryTreeNode* buildTree(int* treeValue,int start,int end){
	if(treeValue == NULL || end < 0 || start < 0)
		return NULL;
	BinaryTreeNode* root = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	root->m_Value = treeValue[start];
	root->m_pLeft = root->m_pRight = NULL;
	if(start == end)
		return root;
	int mid = (end - start) / 2;
	if(mid > 0)
		root->m_pLeft = buildTree(treeValue,start + 1,start + mid);
	if(end - start - mid > 0 && mid >= 0)
		root->m_pRight = buildTree(treeValue,start + mid + 1,end);
	return root;
}
//求解二叉树的镜像
void MirrorRecursively(BinaryTreeNode* pNode){
	if(pNode == NULL)
		return;
	if(pNode->m_pLeft == NULL && pNode->m_pRight == NULL)
		return;
	BinaryTreeNode* temp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = temp;
	if(pNode->m_pLeft)
		MirrorRecursively(pNode->m_pLeft);
	if(pNode->m_pRight)
		MirrorRecursively(pNode->m_pRight);
}
//迭代的方法求解
void Mirror(BinaryTreeNode* pNode){
	if(pNode == NULL)
		return;
	if(pNode->m_pLeft == NULL && pNode->m_pRight == NULL)
		return;
	stack<BinaryTreeNode*> stack1;
	BinaryTreeNode* temp;
	stack1.push(pNode);
	while(!stack1.empty())
	{
		BinaryTreeNode* pTemp = stack1.top();
		stack1.pop();
		if(pTemp->m_pLeft != NULL || pTemp->m_pRight != NULL){
			temp = pTemp->m_pLeft;
			pTemp->m_pLeft = pTemp->m_pRight;
			pTemp->m_pRight = temp;
			if(pTemp->m_pLeft != NULL)
				stack1.push(pTemp->m_pLeft);
			if(pTemp->m_pRight != NULL)
				stack1.push(pTemp->m_pRight);
		}
	}
}

void Test(){
	int a[11] = {1,2,5,3,6,7,4};
	BinaryTreeNode* b = buildTree(a,0,6);
	BinaryTreeNode* c = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	BinaryTreeNode* d = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	BinaryTreeNode* e = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	c->m_Value = 15;
	c->m_pLeft = c->m_pRight = NULL;
	d->m_Value = 11;
	d->m_pLeft = d->m_pRight = NULL;
	e->m_Value = 10;
	e->m_pLeft = e->m_pRight = NULL;
	b->m_pLeft->m_pLeft->m_pLeft = c;
	c->m_pLeft = d;
	c->m_pRight = e;
	Mirror(b);

	printf("%d",*b);
}
