#include <stdio.h>
#include <stdlib.h>
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

ListNode* FindKthToTail(ListNode* pListHead,unsigned int k)
{
	if(pListHead == NULL || k == 0)
		return NULL;
	ListNode* pAhead = pListHead;
	ListNode* pBehind = NULL;
	
	for(unsigned int i = 0;i< k - 1;++i){
		if(pAhead->m_pNext == NULL)
			return NULL;
		pAhead = pAhead->m_pNext;
	}
	pBehind = pListHead;
	while(pAhead->m_pNext != NULL){
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}
	return pBehind;
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
	s = FindKthToTail(head,0);
	if(s != NULL)
		printf("%d",s->m_nValue);
}