#include <stdlib.h>
#include <stdio.h> 
typedef struct Node{
	int m_nValue;
	struct Node *m_pNext;//这地要加上struct关键字
}ListNode,*ListLink;

void addToTail(ListLink* pHead, int value){
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
void removeNode(ListLink* pHead, int value){
	if (pHead == NULL || *pHead == NULL)
		return;
	ListNode* pToBeDelete = NULL;
	if ((*pHead)->m_nValue == value){
		pToBeDelete = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != NULL&&pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;
		if (pNode->m_pNext != NULL&&pNode->m_pNext->m_nValue == value){
			pToBeDelete = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}
	if (pToBeDelete != NULL)
	{
		free (pToBeDelete);
		pToBeDelete = NULL;
	}
}

//从尾到头打印链表;
void PrintListReversingly_Iteratively(ListLink pHead){
	//对于realloc的使用经常出现错误，注意在重新分配内存之前不要用其他的指针名字指向原来的指针;
	ListNode* pNode = pHead;
	int i = 0;
	int size = 0;
	while (pNode != NULL){
		size++;
		pNode = pNode->m_pNext;
	}
	int* nodes = (int*)malloc(sizeof(int)*size);
	if (!nodes)
		return;
	pNode = pHead;
	while (pNode != NULL)
	{
		nodes[i++] = pNode->m_nValue;
		pNode = pNode->m_pNext;
	}
	i = i - 1;
	while (i >= 0){
		printf("%d\t", nodes[i--]);
	}
	printf("\n");
	free(nodes);
	nodes = NULL;
}

void PrintListReversingly_Recursive(ListLink pHead){
	if (pHead != NULL)
	{
		if (pHead->m_pNext != NULL)
			PrintListReversingly_Recursive(pHead->m_pNext);
		printf("%d\t", pHead->m_nValue);
	}
	
}
void Test()
{
	ListLink head = NULL;
	addToTail(&head, 1);
	addToTail(&head, 2);
	addToTail(&head, 3);
	addToTail(&head, 4);
	addToTail(&head, 5);
	addToTail(&head, 6);
	addToTail(&head, 7);
	addToTail(&head, 8);
	addToTail(&head, 9);
	addToTail(&head, 10);

	PrintListReversingly_Iteratively(head);
	PrintListReversingly_Recursive(head);
}