//从上往下打印树，同一层按照从左到右的顺序打印树的节点
#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot){
	if(pTreeRoot == NULL)
		return;
	queue<BinaryTreeNode*> qTemp;
	qTemp.push(pTreeRoot);
	BinaryTreeNode* pNode;
	while(!qTemp.empty()){
		pNode = qTemp.front();
		cout<<pNode->m_nValue<<"\t";
		qTemp.pop();
		if(pNode->m_pLeft != NULL)
			qTemp.push(pNode->m_pLeft);
		if(pNode->m_pRight != NULL)
			qTemp.push(pNode->m_pRight);
	}
}

void Test(){
	BinaryTreeNode* head;
    head = buildTree();
	PrintFromTopToBottom(head);
}


