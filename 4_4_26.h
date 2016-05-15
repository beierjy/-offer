#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

struct ComplexListNode{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

void CloneNodes(ComplexListNode* pHead){
	ComplexListNode* pNode = pHead;
	while(pNode != NULL){
		ComplexListNode* newNode = (ComplexListNode*)malloc(sizeof(ComplexListNode));
		newNode->m_nValue = pNode->m_nValue;
		newNode->m_pNext = pNode->m_pNext;
		newNode->m_pSibling = NULL;
		pNode->m_pNext = newNode;
		pNode = newNode->m_pNext;
	}
}

void ConnectSiblingNodes(ComplexListNode* pHead){
	ComplexListNode* pNode = pHead;
	while(pNode != NULL){
		ComplexListNode* pCloned = pNode->m_pNext;
		if(pNode->m_pSibling!= NULL)
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;

		pNode = pCloned->m_pNext;
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead){
	ComplexListNode* pNode = pHead;
	ComplexListNode* pClonedHead = NULL;
	ComplexListNode* pClonedNode = NULL;
	if(pNode != NULL){
		pClonedHead = pClonedNode = pNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	while(pNode != NULL){
		pClonedNode->m_pNext = pNode->m_pNext;
		pClonedNode = pClonedNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	return pClonedHead;
}

ComplexListNode* clone(ComplexListNode* pHead){
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	ComplexListNode* clone1 = ReconnectNodes(pHead);
	return clone1;
}

ComplexListNode* createNode(int value){
	ComplexListNode* pNode = (ComplexListNode*)malloc(sizeof(ComplexListNode));
	pNode->m_nValue = value;
	pNode->m_pNext = NULL;
	pNode->m_pSibling = NULL;
	return pNode;
}

void BuildNodes(ComplexListNode* pNode,ComplexListNode* pNext,ComplexListNode* pSibling){
	if(pNode != NULL){
		pNode->m_pNext = pNext;
		pNode->m_pSibling = pSibling;
	}
}

void PrintList(ComplexListNode* pHead){
	ComplexListNode* pNode = pHead;
	while(pNode != NULL){
		printf("The value of this node is: %d.\n",pNode->m_nValue);
		if(pNode->m_pSibling != NULL)
			printf("The value of sibling is:%d.\n",pNode->m_pSibling->m_nValue);
		else
			printf("there is not sibling node!\n");
		pNode = pNode->m_pNext;
	}
}

void Test(){
	ComplexListNode* pNode1 = createNode(1);
	ComplexListNode* pNode2 = createNode(2);
	ComplexListNode* pNode3 = createNode(3);
	ComplexListNode* pNode4 = createNode(4);
	ComplexListNode* pNode5 = createNode(5);

	BuildNodes(pNode1,pNode2,pNode1);
	BuildNodes(pNode2,pNode3,pNode4);
	BuildNodes(pNode3,pNode4,NULL);
	BuildNodes(pNode4,pNode5,pNode2);
	PrintList(pNode1);
	ComplexListNode* clone1 = clone(pNode1);
	PrintList(clone1);
}





