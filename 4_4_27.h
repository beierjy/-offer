#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void ConvertNode(BinaryTreeNode* pNode,BinaryTreeNode** pLastNodeInList){
	if(pNode == NULL)
		return;
	BinaryTreeNode* pCurrent = pNode;
	if(pCurrent->m_pLeft != NULL)
		ConvertNode(pCurrent->m_pLeft,pLastNodeInList);
	pCurrent->m_pLeft = *pLastNodeInList;
	if((*pLastNodeInList) != NULL)
		(*pLastNodeInList)->m_pRight = pCurrent;
	*pLastNodeInList = pCurrent;
	if(pCurrent->m_pRight != NULL)
		ConvertNode(pCurrent->m_pRight,pLastNodeInList);
}


BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree){
	if(pRootOfTree == NULL)
		return NULL;
	BinaryTreeNode* pLastNodeInList = NULL;
	ConvertNode(pRootOfTree,&pLastNodeInList);

	BinaryTreeNode* pHead = pLastNodeInList;
	while(pHead != NULL && pHead->m_pLeft != NULL)
		pHead = pHead->m_pLeft;
	return pHead;
}
void Test(){
	BinaryTreeNode *head = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	head->m_nValue = 10;
	BinaryTreeNode *a = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	BinaryTreeNode *c = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	BinaryTreeNode *d = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	BinaryTreeNode *e = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	BinaryTreeNode *f = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	BinaryTreeNode *h = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	a->m_nValue = 6;
	c->m_nValue = 4;
	d->m_nValue = 8;
	e->m_nValue = 14;
	f->m_nValue = 12;
	h->m_nValue = 16;
	head->m_pLeft = a;
	head->m_pRight = e;
	a->m_pLeft = c;
	a->m_pRight = d;
	e->m_pLeft = f;
	e->m_pRight = h;
	c->m_pLeft = NULL;
	c->m_pRight = NULL;
	d->m_pLeft = NULL;
	d->m_pRight = NULL;
	f->m_pLeft = NULL;
	f->m_pRight = NULL;
	h->m_pLeft = NULL;
	h->m_pRight = NULL;
	BinaryTreeNode *i = Convert(head);
	free(head);free(a);free(c);free(d);free(e);free(f);free(h);
	head = a = c=d=e=f=h = NULL;
}






