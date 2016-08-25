#include <queue>
#include <stack>
#include <iostream>

using namespace std;
typedef struct Node{
	int value;
	struct Node* p_left;
	struct Node* p_right;
}BinaryTreeNode;

void Print(BinaryTreeNode* pRoot){
	if(pRoot == NULL)
		return;
	stack<BinaryTreeNode* > s1;
	stack<BinaryTreeNode* > s2;
	int numNext=0;
	int numToBe = 1;
	int tag = 1;
	s1.push(pRoot);
	BinaryTreeNode* pNode = NULL;
	while(!s1.empty()||!s2.empty()){
		if(!s1.empty()&& tag == 1){
			pNode = s1.top();
			if(pNode->p_left != NULL){
				s2.push(pNode->p_left);
				numNext++;
			}
			if(pNode->p_right != NULL){
				s2.push(pNode->p_right);
				numNext++;
			}
			
			cout<<pNode->value<<"\t";
			numToBe--;
			s1.pop();
			if(numToBe==0){
				cout<<endl;
				numToBe = numNext;
				numNext = 0;
				tag = tag^1;
			}
		}
		if(!s2.empty()&& tag == 0){
			pNode = s2.top();
			if(pNode->p_right != NULL){
				s1.push(pNode->p_right);
				numNext++;
			}
			if(pNode->p_left != NULL){
				s1.push(pNode->p_left);
				numNext++;
			}
			
			cout<<pNode->value<<"\t";
			numToBe--;
			s2.pop();
			if(numToBe==0){
				cout<<endl;
				numToBe = numNext;
				numNext = 0;
				tag = tag^1;
			}
		}
	}
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
	Print(root);
	delete root;
	delete a;delete b;delete c;delete d;delete e;delete f;
	delete g;delete h;delete i;delete j;delete k;delete l;
	delete m;delete n;
}
