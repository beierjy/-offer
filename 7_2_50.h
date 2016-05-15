#include <iostream>
#include <list>

using namespace std;

struct TreeNode{
	int m_value;
	TreeNode* p_sib;
	TreeNode* p_ch;
};
bool GetNodePath(TreeNode* pRoot,TreeNode* pNode,list<TreeNode*> &path){
	if(pRoot == pNode)
		return true;
	TreeNode* pTemp = pRoot;
	path.push_back(pRoot);
	while(!path.empty()){
		while(pTemp->p_ch != NULL ){
			if(pTemp == pNode)
				break;
			pTemp = pTemp->p_ch;
			path.push_back(pTemp);
		}
		if(pTemp == pNode)
			break;
		pTemp = path.back();
		path.pop_back();
		while(pTemp->p_sib == NULL && !path.empty()){
			pTemp = path.back();
			path.pop_back();
		}
		if(path.empty())
			break;
		else{
			pTemp = pTemp->p_sib;
			path.push_back(pTemp);
		}	
	}
	if(path.empty())
		return false;
	return true;
}
TreeNode* GetLastCommonNode(const list<TreeNode*> path1,const list<TreeNode*> path2){
	list<TreeNode*>::const_iterator iter1 = path1.begin();
	list<TreeNode*>::const_iterator iter2 = path2.begin();
	TreeNode* pLast = NULL;
	while(iter1 != path1.end() && iter2 != path2.end()){
		if(*iter1 == *iter2)
			pLast = *iter1;
		iter1++;
		iter2++;
	}
	return pLast;
}
TreeNode* GetLastCommonParent(TreeNode* pRoot,TreeNode* pNode1,TreeNode* pNode2)
{
	if(pRoot == NULL || pNode1 == NULL || pNode2 == NULL)
		return NULL;
	list<TreeNode*> path1;
	list<TreeNode*> path2;
	GetNodePath(pRoot,pNode1,path1);
	GetNodePath(pRoot,pNode2,path2);
	return GetLastCommonNode(path1,path2);
}
void Test(){
	TreeNode* root = new TreeNode;
	root->m_value = 1;
	root->p_sib = NULL;
	TreeNode a;
	a.m_value = 2;
	root->p_ch = &a;
	TreeNode b;
	b.m_value = 3;
	a.p_sib = &b;
	b.p_ch = b.p_sib = NULL;
	TreeNode c;
	c.m_value = 4;
	a.p_ch = &c;
	c.p_ch=c.p_sib = NULL;
	TreeNode d;
	d.m_value = 5;
	c.p_sib= &d;
	d.p_ch=d.p_sib = NULL;
	TreeNode e;
	e.m_value = 6;
	c.p_ch= &e;
	e.p_ch=e.p_sib = NULL;
	TreeNode f;
	f.m_value = 7;
	e.p_sib= &f;
	f.p_ch=f.p_sib = NULL;
	TreeNode h;
	h.m_value = 8;
	d.p_ch= &h;
	h.p_ch=h.p_sib = NULL;
	TreeNode i;
	i.m_value = 9;
	h.p_sib= &i;
	i.p_ch=i.p_sib = NULL;
	TreeNode* r;
	r = GetLastCommonParent(root,&h,&i);
	cout<<r->m_value<<endl;
}





