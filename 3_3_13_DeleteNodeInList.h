//删除链表里指定的节点
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int m_nValue;
	struct Node* m_pNext;
}listNode,*listLink;

void InsertNode(listLink* pListHead,int m_value){
	if(pListHead == NULL)
		return;
	listNode* ptr =(listNode*)malloc(sizeof(listNode));
	if(!ptr)
		return;
	ptr->m_nValue = m_value;
	ptr->m_pNext = *pListHead;
	*pListHead = ptr;
}
//普通的方法删除
void DeleteNode(listLink *pListHead,listNode* pToBeDelete){
	if(pListHead == NULL|| !pToBeDelete)
		return;
	if(*pListHead == pToBeDelete)
		*pListHead = (*pListHead)->m_pNext;
	listNode *pre = *pListHead;
	while(pre->m_pNext != pToBeDelete && pre->m_pNext != NULL)
		pre = pre->m_pNext;
	if(pre->m_pNext == NULL)
		return;
	if(pToBeDelete != NULL)
		pre->m_pNext = pToBeDelete->m_pNext;
	else pre->m_pNext = NULL;
	free(pToBeDelete);
	pToBeDelete = NULL;
}
//替换的方法
void DeleteNode1(listLink *pListHead,listNode* pToBeDelete){
	if(!pListHead || !pToBeDelete)
		return;
	if(pToBeDelete->m_pNext != NULL){
			listNode* temp = pToBeDelete->m_pNext;
			pToBeDelete->m_nValue = pToBeDelete->m_pNext->m_nValue;
			pToBeDelete->m_pNext = pToBeDelete->m_pNext->m_pNext;
			pToBeDelete = temp;
	}
	else if(pToBeDelete->m_pNext == NULL){
		if(*pListHead == pToBeDelete){
			*pListHead = NULL;
		}
		else{
			listNode *pre = *pListHead;
			while(pre->m_pNext != pToBeDelete && pre->m_pNext != NULL)
				pre = pre->m_pNext;
			if(pre->m_pNext == NULL)
				return;
			pre->m_pNext = NULL;
		}
	}
	free(pToBeDelete);
	pToBeDelete = NULL;
}

void PrintListReversingly_Recursive(listLink pHead){
	if (pHead != NULL)
	{
		if (pHead->m_pNext != NULL)
			PrintListReversingly_Recursive(pHead->m_pNext);
		printf("%d\t", pHead->m_nValue);
	}
	
}
void Test()
{
	listLink head = NULL;
	InsertNode(&head, 1);
	InsertNode(&head, 2);
	InsertNode(&head, 3);
	InsertNode(&head, 4);
	InsertNode(&head, 5);
	listNode* p = head;
	while(p->m_nValue != 5 && p->m_pNext!= NULL)
		p=p->m_pNext;
	if(p->m_nValue!= 5)
		p = NULL;
	//DeleteNode1(&head,p);
	DeleteNode(&head,p);
	PrintListReversingly_Recursive(head);
}
