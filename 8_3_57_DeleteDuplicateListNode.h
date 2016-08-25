/*在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
重复的结点不保留，返回链表头指针。
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/
#include <iostream>
using namespace std;
typedef struct Node{
	int m_value;
	struct Node* next;
}ListNode;
//my
void deleteDuplication(ListNode** pHead){
	if(pHead == NULL || *pHead == NULL)
		return;
	ListNode* pPre = NULL;
	ListNode* pNode = *pHead;
	ListNode* pNext = NULL;
	if(pNode->next != NULL)
		pNext = pNode->next;
	while(pNode != NULL && pNext != NULL){
		if(pNode->m_value == pNext->m_value){
			while(pNext != NULL && pNode->m_value == pNext->m_value)
			{
				pNode->next = pNext->next;
				delete pNext;
				pNext= NULL;
				pNext = pNode->next;
			}
			ListNode* ptmp = pNode->next;
			if(*pHead == pNode)
				*pHead = ptmp;
			delete pNode;
			pNode = NULL;
			pNode = ptmp;
			pNext = pNode->next;
		}
		else{
			pPre = pNode;
			pNode = pNext;
			pNext = pNext->next;
		}
	}
}
void deleteDuplication1(ListNode** pHead){
	if(pHead== NULL || *pHead == NULL)
		return;
	ListNode* pPreNode =NULL;
	ListNode* pNode = *pHead;
	while(pNode != NULL){
		ListNode *pNext = pNode->next;
		bool needDelete = false;
		if(pNext != NULL && pNext->m_value == pNode->m_value)
			needDelete = true;
		if(!needDelete)
		{
			pPreNode = pNode;
			pNode = pNode->next;
		}
		else{
			int value = pNode->m_value;
			ListNode* pToBeDel = pNode;
			while(pToBeDel != NULL && pToBeDel->m_value == value)
			{
				pNext = pToBeDel->next;
				delete pToBeDel;
				pToBeDel = NULL;
				pToBeDel = pNext;
			}
			if(pPreNode == NULL)
				*pHead = pNext;
			else
				pPreNode->next = pNext;
			pNode = pNext;
		}
	}
}

void Test(){
	ListNode* head = new ListNode;
	head->m_value = 2;
	ListNode *a = new ListNode;
	a->m_value = 2;
	head->next = a;
	ListNode *b = new ListNode;
	b->m_value = 2;
	a->next = b;
	ListNode *c = new ListNode;
	c->m_value = 4;
	b->next = c;
	ListNode *d = new ListNode;
	d->m_value = 4;
	c->next = d;
	ListNode *e = new ListNode;
	e->m_value = 6;
	d->next = e;
    e->next = NULL;
	deleteDuplication1(&head);
	
}

