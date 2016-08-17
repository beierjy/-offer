//反转链表，注意空链表，链表只有一个元素的情况
#include <stdlib.h>
#include <stdio.h>

struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
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
ListNode* ReverseList(ListNode* pHead){
	if(pHead == NULL || pHead->m_pNext == NULL)
		return pHead;
	ListNode* pReversedHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while(pNode != NULL){
		ListNode* pNext = pNode->m_pNext;
		if(pNext == NULL)
			pReversedHead = pNode;
		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReversedHead;
}
void Test(){
	ListNode* head = NULL;//注意这里一定要初始化为NULL否则不指定分配了什么数
	addToTail(&head, 1);
	addToTail(&head, 2);
	addToTail(&head, 3);
	addToTail(&head, 4);
	addToTail(&head, 5);
	addToTail(&head, 6);
	addToTail(&head, 7);
	addToTail(&head, 8);

	ListNode* s;
	s =  ReverseList(head);
	while(s != NULL){
		printf("%d",s->m_nValue);
		s =s->m_pNext;
	}
}
