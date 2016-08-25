#include <iostream>

using namespace std;

typedef struct Node{
	char m_value;
	struct Node* p_left;
	struct Node* p_right;
	struct Node* p_parent;
}BinaryTreeNode;
BinaryTreeNode* GetNext(BinaryTreeNode* pNode){
	if(pNode == NULL)
		return NULL;
	BinaryTreeNode* pNext = NULL;
	if(pNode->p_right != NULL){
		BinaryTreeNode* right = pNode->p_right;
		while(right->p_left != NULL)
			right = right->p_left;
		pNext = right;
	}
	else if(pNode->p_parent != NULL){
		BinaryTreeNode* parent = pNode->p_parent;
		while(parent->p_left != pNode && parent->p_parent != NULL){
			pNode = parent;
			parent = parent->p_parent;
		}
		if(parent->p_left == pNode)
			pNext = parent;
	}
	return pNext;
}

