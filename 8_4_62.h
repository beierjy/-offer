#include <sstream>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;
typedef struct Node{
	int value;
	struct Node* p_left;
	struct Node* p_right;
}BinaryTreeNode;

void Serialize(BinaryTreeNode* pRoot,ostream& stream){
	if(pRoot == NULL)
	{
		stream<<"$,";
		return;
	}
	stream<<pRoot->value<<',';
	Serialize(pRoot->p_left,stream);
	Serialize(pRoot->p_right,stream);
}
bool ReadStream(istream& stream,int* number){
	if(stream.eof())
		return false;
	char temp;int tmp;
	*number = 0;
	stringstream ss;
	stream>>temp;
	if(!stream.eof()&&temp == ',')
		stream>>temp;
	if(!stream.eof() && isdigit(temp)){
		while(temp != ','&&isdigit(temp)){
			ss<<temp;
			ss>>tmp;
			*number = *number*10 + tmp ;
			stream>>temp;
		}
		return true;
	}
	return false;
}
void Deserialize(BinaryTreeNode** pRoot,istream& stream){
	int number;
	if(ReadStream(stream,&number)){
		*pRoot = new BinaryTreeNode;
		(*pRoot)->value = number;
		(*pRoot)->p_left= NULL;
		(*pRoot)->p_right= NULL;
		Deserialize(&((*pRoot)->p_left),stream);
		Deserialize(&((*pRoot)->p_right),stream);
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
	e->p_left = NULL;//k
	e->p_right = l;
	f->p_left = m;
	f->p_right = n;
	g->p_left=g->p_right = h->p_left = h->p_right = i->p_left = i->p_right = j->p_left = j->p_right = NULL;
	k->p_left=k->p_right = l->p_left = l->p_right = m->p_left = m->p_right = n->p_left = n->p_right = NULL;
	stringstream ss;
	string str;
	Serialize(root,ss);
	BinaryTreeNode *root1;
	Deserialize(&root1,ss);
	ss>>str;
	cout<<str;
	delete root;
	delete a;delete b;delete c;delete d;delete e;delete f;
	delete g;delete h;delete i;delete j;delete k;delete l;
	delete m;delete n;
}