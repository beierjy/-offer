#include <iostream>
#include <cstdlib>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x=0):val(x),next(NULL){
    }
};
ListNode* FindFirstCommonNode(ListNode* pHead1,ListNode* pHead2){
    if(pHead1 == NULL || pHead2 == NULL)
        return NULL;
    ListNode* pNode1;ListNode* pNode2;
    int len1 = 0;int len2 = 0;
    for(pNode1 = pHead1;pNode1 != NULL;pNode1 = pNode1->next){
        len1++;
    }
     for(pNode2 = pHead2;pNode2 != NULL;pNode2 = pNode2->next){
        len2++;
    }
    pNode1 = pHead1;
    pNode2 = pHead2;
    if(len1 > len2){
        int i = len1  - len2;
        while(i > 0){
                i--;
                pNode1 = pNode1->next;
        }
    }
    else{
        int i = len2  - len1;
        while(i > 0){
                i--;
                pNode1 = pNode1->next;
        }
    }
    while(pNode1 != pNode2 && pNode1!= NULL&&*pNode1!=*pNode2){
        pNode1 = pNode1->next;
        pNode2 = pNode2->next;
    }
    return pNode1;
}
void Test(){
    ListNode phead1,phead2;
    ListNode a(3);
    ListNode b(4);
    ListNode c(5);
    ListNode d(6);
    ListNode e(7);
    ListNode f(2);
    a.next=&b;
    b.next=&c;
    c.next=&d;
    e.next=&f;
    f.next=&c;
    c.next=&d;
	phead2=e;
	phead1=a;
    ListNode* com;
    com = FindFirstCommonNode(&phead1,&phead2);
    while(com != NULL){
        cout<<com->val<<" ";
        com = com->next;
    }
}
