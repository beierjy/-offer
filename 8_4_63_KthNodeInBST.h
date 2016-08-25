#include <iostream>
using namespace std;

typedef struct Node{
	int value;
	struct Node* p_left;
	struct Node* p_right;
}BinaryTreeNode;
//两次递归效率很低
int countNodes(BinaryTreeNode* pRoot){
	if(pRoot == NULL)
		return 0;
	int left = countNodes(pRoot->p_left);
	int right = countNodes(pRoot->p_right);
	return 1+ left + right;
}
BinaryTreeNode* KthNode(BinaryTreeNode* pRoot,int k){
	if(pRoot == NULL || k <= 0)
		return NULL;
	int cnt = countNodes(pRoot->p_left);
	if(cnt + 1 == k)
		return pRoot;
	else if(cnt + 1 < k)
		return KthNode(pRoot->p_right,k-cnt-1);
	else
		return KthNode(pRoot->p_left,k);
}
//采用中序遍历，一次递归
BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot,unsigned int& k){
	BinaryTreeNode* target = NULL;
	if(pRoot->p_left != NULL)
		target = KthNodeCore(pRoot->p_left,k);
	if(target == NULL){
		if(k == 1)
			return pRoot;
		k--;
	}
	if(target== NULL && pRoot->p_right != NULL)
		target = KthNodeCore(pRoot->p_right,k);
	return target;
}
BinaryTreeNode* KthNode1(BinaryTreeNode* pRoot,unsigned int& k){
	if(pRoot== NULL || k == 0)
		return NULL;
	return KthNodeCore(pRoot,k);
}
void Test(){
	BinaryTreeNode *root = new BinaryTreeNode;
	BinaryTreeNode *a = new BinaryTreeNode;
	BinaryTreeNode *b = new BinaryTreeNode;
	BinaryTreeNode *c = new BinaryTreeNode;
	BinaryTreeNode *d = new BinaryTreeNode;
	BinaryTreeNode *e = new BinaryTreeNode;
	BinaryTreeNode *f = new BinaryTreeNode;
	BinaryTreeNode *g = new BinaryTreeNode;
	BinaryTreeNode *h = new BinaryTreeNode;
	BinaryTreeNode *i = new BinaryTreeNode;
	BinaryTreeNode *j = new BinaryTreeNode;
	BinaryTreeNode *k = new BinaryTreeNode;
	BinaryTreeNode *l = new BinaryTreeNode;
	BinaryTreeNode *m = new BinaryTreeNode;
	BinaryTreeNode *n = new BinaryTreeNode;
	root->value = 1;
	root->p_left = a;
	root->p_right = b;
	a->value = 2;
	b->value = 3;
	a->p_left = c;
	a->p_right = d;
	b->p_left = e;
	b->p_right = f;
	c->value = 4;
	d->value = 5;
	e->value = 6;
	f->value = 7;
	g->value = 8;
	h->value = 9;
	i->value = 10;
	j->value = 11;
	k->value = 12;
	l->value = 13;
	m->value = 14;
	n->value = 15;
	c->p_left=g;
	c->p_right =h;
	d->p_left = i;
	d->p_right = j;
	e->p_left = k;
	e->p_right = l;
	f->p_left = m;
	f->p_right = n;
	g->p_left=g->p_right = h->p_left = h->p_right = i->p_left = i->p_right = j->p_left = j->p_right = NULL;
	k->p_left=k->p_right = l->p_left = l->p_right = m->p_left = m->p_right = n->p_left = n->p_right = NULL;
	unsigned int s = 7;
	BinaryTreeNode* p = KthNode1(root,s);
	cout<<p->value<<endl;
	delete root;
	delete a;delete b;delete c;delete d;delete e;delete f;
	delete g;delete h;delete i;delete j;delete k;delete l;
	delete m;delete n;
}
