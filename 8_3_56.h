#include <iostream>

using namespace std;

typedef struct Node{
	int m_value;
	struct Node* next;
}ListNode;

ListNode* MeetingNode(ListNode* pHead){
	if(pHead == NULL)
		return NULL;
	ListNode* pSlow = pHead->next;
	if(pSlow == NULL)
		return NULL;
	ListNode* pFast = pSlow->next;
	while(pFast != NULL && pSlow != NULL){
		if(pFast == pSlow)
			return pFast;
		pSlow = pSlow->next;
		pFast = pFast->next;
		if(pFast != NULL)
			pFast = pFast->next;
	}
	return NULL;
}
ListNode* EntryNodeofLoop(ListNode* pHead){
	ListNode* meetingNode = MeetingNode(pHead);
	if(meetingNode == NULL)
		return NULL;
	int nodesInLoop = 1;
	ListNode* pNode = meetingNode->next;
	while(pNode != meetingNode){
		nodesInLoop++;
		pNode = pNode->next;
	}
	pNode = pHead;
	while(nodesInLoop > 0){
		pNode = pNode->next;
		nodesInLoop--;
	}
	ListNode* pNode1 = pHead;
	while(pNode1 != pNode){
		pNode=pNode->next;
		pNode1=pNode1->next;
	}
	return pNode;
}
void Test(){
	ListNode* head = new ListNode;
	head->m_value = 1;
	ListNode *a = new ListNode;
	a->m_value = 2;
	head->next = a;
	ListNode *b = new ListNode;
	b->m_value = 3;
	a->next = b;
	ListNode *c = new ListNode;
	c->m_value = 4;
	b->next = c;
	ListNode *d = new ListNode;
	d->m_value = 5;
	c->next = d;
	ListNode *e = new ListNode;
	e->m_value = 6;
	d->next = e;
    e->next = b;
	ListNode *f;//不能new一个
	f = EntryNodeofLoop(head);
	cout<<f->m_value<<endl;
	delete head;
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
}

