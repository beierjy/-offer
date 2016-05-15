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
	queue<BinaryTreeNode* > q;
	stack<int> s;
	queue<int> q1;
	int numNext=0;
	int numToBe = 1;
	int tag = 1;
	q.push(pRoot);
	BinaryTreeNode* pNode = NULL;
	while(!q.empty()){
		pNode = q.front();
		if(pNode->p_left != NULL){
			q.push(pNode->p_left);
			numNext++;
		}
		if(pNode->p_right != NULL){
			q.push(pNode->p_right);
			numNext++;
		}
		if(tag == 1)
			q1.push(pNode->value);
		else
			s.push(pNode->value);
		numToBe--;
		q.pop();
		if(numToBe==0){
			int  a;
			if(tag == 0){
				while(!s.empty()){
					a = s.top();
					cout<<a<<"\t";
					s.pop();
				}
			}
			else{
				while(!q1.empty()){
					a = q1.front();
					cout<<a<<"\t";
					q1.pop();
				}
			}
			cout<<endl;
			numToBe = numNext;
			numNext = 0;
			tag = tag^1;
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
	root->value = 8;
	root->p_left = a;
	root->p_right = b;
	a->value = 6;
	b->value = 10;
	a->p_left = c;
	a->p_right = d;
	b->p_left = e;
	b->p_right = f;
	c->value = 5;
	d->value = 7;
	e->value = 9;
	f->value = 11;
	c->p_left=c->p_right = d->p_left = d->p_right = e->p_left = e->p_right = f->p_left = f->p_right = NULL;
	Print(root);
	delete root;
	delete a;delete b;delete c;delete d;delete e;delete f;
}
