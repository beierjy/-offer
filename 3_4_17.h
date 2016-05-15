#include <stdlib.h>
#include <stdio.h> 
struct ListNode{
	int m_nValue;
	ListNode *m_pNext;
};

void addToTail(ListNode** pHead, int value){
	ListNode* pNew = (ListNode*)malloc(sizeof(ListNode));
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;
	if (*pHead == NULL)
		*pHead = pNew;
	else{
		ListNode * pNode = *pHead;
		while (pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		pNode->m_pNext = pNew;
	}
}

ListNode* Merge(ListNode* pHead1,ListNode* pHead2){
	if(pHead1 == NULL)
		return pHead2;
	if(pHead2 == NULL)
		return pHead1;
	ListNode* pMergedNode = NULL;
	if(pHead1->m_nValue <= pHead2->m_nValue){
		pMergedNode = pHead1;
		pMergedNode->m_pNext = Merge(pHead1->m_pNext,pHead2);
	}
	else{
		pMergedNode = pHead2;
		pMergedNode->m_pNext = Merge(pHead1,pHead2->m_pNext);
	}
	return pMergedNode;
}


void PrintListReversingly_Recursive(ListNode* pHead){
	if (pHead != NULL)
	{
		if (pHead->m_pNext != NULL)
			PrintListReversingly_Recursive(pHead->m_pNext);
		printf("%d\t", pHead->m_nValue);
	}
}
void Test(){
	ListNode* head1 = NULL;//注意这里一定要初始化为NULL否则不指定分配了什么数
	ListNode* head2 = NULL;
	addToTail(&head1, 1);
	addToTail(&head2, 2);
	addToTail(&head2, 3);
	addToTail(&head1, 4);
	addToTail(&head2, 5);
	addToTail(&head1, 6);
	addToTail(&head1, 7);
	addToTail(&head2, 8);

	ListNode* s;
	s =  Merge(NULL,head2);
	while(s != NULL){
		printf("%d",s->m_nValue);
		s =s->m_pNext;
	}
}