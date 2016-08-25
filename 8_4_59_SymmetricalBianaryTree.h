typedef struct Node{
	int m_value;
	struct Node* p_left;
	struct Node* p_right;
}BinaryTreeNode;
bool isSymmetrical(BinaryTreeNode* pNode1,BinaryTreeNode* pNode2){
	if(pNode1 == NULL && pNode2 == NULL)
		return true;
	if(pNode1 == NULL || pNode2 == NULL)
		return false;
	if(pNode1->m_value != pNode2->m_value)
		return false;
	return isSymmetrical(pNode1->p_left,pNode1->p_right) && isSymmetrical(pNode2->p_left,pNode2->p_right);
}
bool isSymmetrical(BinaryTreeNode* pRoot){
	return isSymmetrical(pRoot,pRoot);
}


