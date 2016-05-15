#include<stack>
#include<queue>
#include <iostream>

using namespace std;

#ifndef CQUEUE_H
#define CQUEUE_H
template <class T> class CQueue{
public:
	CQueue(void){}
	~CQueue(){}
	void appendTail(const T& node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};
#endif

template<class T>
void CQueue<T>::appendTail(const T& element){
	stack1.push(element);
}

template<class T>
T CQueue<T>::deleteHead(){
	T temp;
	if (stack2.empty()){
		while (!stack1.empty())
		{
			temp = stack1.top();
			stack2.push(temp);
			stack1.pop();
		}
	}
	if (stack2.empty()){
		throw new exception("queue is empty\n");
		return 0;
	}
	temp = stack2.top();
	stack2.pop();
	return temp;
}

void Test1(){
	CQueue<int> q;
	q.appendTail(1);
	q.appendTail(2);
	q.appendTail(3);
	int a, b, c, d;
	a = q.deleteHead();
	b = q.deleteHead();
	c = q.deleteHead();
	d = q.deleteHead();
	cout << a << b << c << endl;
}
#ifndef CSTACK_H
#define CSTACK_H
template <class T> class CStack{
public:
	CStack(void){}
	~CStack(){}
	void insert(const T&);
	T del();
private:
	queue<T> queue1;
	queue<T> queue2;
};
#endif
template<class T>
void CStack<T>::insert(const T& element){
	/*T temp;没有必要的
	if (!queue1.empty())
	{
		while (!queue1.empty())
		{
			temp = queue1.front();
			queue2.push(temp);
			queue1.pop();
		}
	}*/
	queue1.push(element);
}

template <class T>
T CStack<T>::del()
{
	T temp;
	if (queue1.empty() && queue2.empty())
	{
		throw new exception("no elements in queues");
		return 0;
	}
	if (queue1.size() >= 1)
	{
		while (queue1.size() > 1){
			temp = queue1.front();
			queue1.pop();
			queue2.push(temp);
		}
		temp = queue1.front();
		queue1.pop();
	}
	else if (queue2.size() >= 1)
	{
		while (queue2.size() > 1){
			temp = queue2.front();
			queue2.pop();
			queue1.push(temp);
		}	
		temp = queue2.front();
		queue2.pop();
	}
	
	return temp;
}
void Test2(){
	int a, b, c, d, e;
	CStack<int> s;
	s.insert(1);
	s.insert(2);
	a = s.del();
	b = s.del();
	s.insert(3);
	s.insert(4); 
	
	c = s.del();
	d = s.del();
	e = s.del();
	cout << endl << a << b << c << d << e << endl;
}