#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;
template<class T>
struct StackWithMin{
	void push(const T& value);
	void pop();
	const T& min()const;
	stack<T> m_data;
	stack<T> m_min;
};

template<class T> 
void StackWithMin<T>::push(const T &value){
	m_data.push(value);
	if(m_min.size() == 0 || value < m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}
template<class T>
void StackWithMin<T>::pop(){
	assert(m_data.size() > 0 && m_min.size()>0);
	m_data.pop();
	m_min.pop();
}

template<class T>
const T& StackWithMin<T>::min()const{
	assert(m_data.size() > 0 && m_min.size() > 0);
	return m_min.top();
}

void Test(){
	StackWithMin<int> swm;
	swm.push(1);
	swm.push(2);
	swm.push(4);
	swm.push(3);
	swm.push(0);
	printf("%d",swm.min());
	swm.pop();
	swm.pop();
	swm.pop();
	swm.pop();
	swm.pop();
	swm.pop();
	printf("%d",swm.min());
}

