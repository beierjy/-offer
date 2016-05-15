#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2){
	if(pRoot2 == NULL)
		return true;
	if(pRoot1 == NULL)
		return false;
	if(pRoot1->m_nValue != pRoot2->m_nValue)
		return false;
	return DoesTree1HaveTree2(pRoot1->m_pLeft,pRoot2->m_pLeft) && DoesTree1HaveTree2(pRoot1->m_pRight,pRoot2->m_pRight);
}
bool HasSubtree(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2){
	bool result = false;
	if(pRoot1 != NULL && pRoot2 != NULL){
		if(pRoot1->m_nValue == pRoot2->m_nValue)
			result = DoesTree1HaveTree2(pRoot1,pRoot2);
		if(!result)
			result = HasSubtree(pRoot1->m_pLeft,pRoot2);
		if(!result)
			result = HasSubtree(pRoot1->m_pRight,pRoot2);
	}
	return result;
}
BinaryTreeNode* build(int* startPreOrder,int* endPreOrder,int* startInOrder,int* endInOrder){
	int rootValue = startPreOrder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;
	if(startPreOrder == endPreOrder){
		if(startInOrder == endInOrder && *startPreOrder == *startInOrder)
			return root;
		else{
			perror("Invalid Input");
			return NULL;
		}
	}
	//在中序中找到根节点;
	int* rootInOrder = startInOrder;
	while(rootInOrder <= endInOrder && *rootInOrder != rootValue)
		++rootInOrder;
	if(rootInOrder == endInOrder && *rootInOrder != rootValue){
		perror("Invalid Input");
		return NULL;
	}
	int leftLength = rootInOrder - startInOrder;
	int* leftPreOrderEnd = startPreOrder + leftLength;
	if(leftLength > 0)
		root->m_pLeft = build(startPreOrder + 1,leftPreOrderEnd,startInOrder,rootInOrder - 1);
	if(leftLength < endPreOrder - startPreOrder)
		root->m_pRight = build(leftPreOrderEnd + 1,endPreOrder,rootInOrder + 1,endInOrder);
	return root;
}
BinaryTreeNode* buildTree(int* preorder, int* inorder, int length){
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;
	else
		return build(preorder, preorder + length - 1, inorder, inorder + length - 1);
}
void Test(){
	int a[7] = {1,2,4,5,3,6,7};
	int b[7] = {4,2,5,1,6,3,7};
	int c[3] = {3,6,7};
	int d[3] = {6,3,7};

	BinaryTreeNode* f = buildTree(a,b,7);
	BinaryTreeNode* h = buildTree(c,d,3);
	int e = HasSubtree(f,h);
	printf("%d",e);
}
