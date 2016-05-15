#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
void FindPath(BinaryTreeNode *pRoot,int expectedSum,vector<int>& path,int currentSum){
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);
	bool isLeaf = pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL;
	if(currentSum == expectedSum && isLeaf)
	{
		printf("The path is found\n");
		vector<int>::iterator iter = path.begin();
		while(iter != path.end()){
			printf("%d\t",*iter);
			++iter;
		}
		printf("\n");
	}
	if(pRoot->m_pLeft != NULL)
		FindPath(pRoot->m_pLeft,expectedSum,path,currentSum);
	if(pRoot->m_pRight != NULL)
		FindPath(pRoot->m_pRight,expectedSum,path,currentSum);
	path.pop_back();
}

void FindPath(BinaryTreeNode* pRoot,int expectedSum){
	if(pRoot == NULL)
		return;
	vector<int> path;
	int currentSum = 0;
	FindPath(pRoot,expectedSum,path,currentSum);
}
void Test(){
	BinaryTreeNode* head = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));;
	head->m_nValue = 10;
	BinaryTreeNode* a = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	BinaryTreeNode* b = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	BinaryTreeNode* c = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	BinaryTreeNode* d = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	a->m_nValue = 5;
	b->m_nValue = 12;
	c->m_nValue = 4;
	d->m_nValue = 7;
	b->m_pLeft = b->m_pRight = NULL;
	c->m_pLeft = c->m_pRight = NULL;
	d->m_pLeft = d->m_pRight = NULL;
	head->m_pLeft = a;
	head->m_pRight = b;
	a->m_pLeft = c;
	a->m_pRight = d;
	FindPath(NULL,19);
	free (d);
	free  (c);
	free(b);
	free(a);
	free(head);
}
