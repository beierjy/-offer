#include <vector>
#include <iostream>
#include <deque>
#include <math.h>

using namespace std;
int maxin(vector<int> num)
{
	int max = 0xFFFFFFFF;
	unsigned int pos = 0;
	while(pos < num.size()){
		if(num[pos] > max)
			max = num[pos];
		pos++;
	}
	return max;
}
vector<int> maxInWindows(vector<int> numbers,unsigned int k){
	vector<int> maxIn;
	if(k < 1)
		return maxIn;
	if(numbers.size() < k){
		maxIn.push_back(maxin(numbers));
	}
	unsigned int pos = 0;
	deque<unsigned int> dPos;
	while(pos < k && pos < numbers.size()){
		while(!dPos.empty()&& (pos - dPos.front() < k)&& numbers[pos] > numbers[dPos.back()])
				dPos.pop_back();
			dPos.push_back(pos);
			pos++;
		}
	pos = k-1;
	while(pos < numbers.size()){
		if(pos > k-1){
			while(!dPos.empty()&& (pos - dPos.front() < k)&& numbers[pos] > numbers[dPos.back()])
				dPos.pop_back();
			dPos.push_back(pos);
		}
		if(!dPos.empty() && pos > k-1 && pos - dPos.front() >= k)
			dPos.pop_front();
		if(!dPos.empty())
			maxIn.push_back(numbers[dPos.front()]);
		pos++;
	}
	return maxIn;
}
vector<int> maxInWindows1(const vector<int>&num,unsigned int size){
	vector<int> maxInWindows;
	if(num.size() >= size && size >= 1){
		deque<int> index;
		for(unsigned int i = 0;i < size;++i){
			while(!index.empty()&&num[i] >= num[index.back()])
				index.pop_back();
			index.push_back(i);
		}
		for(unsigned int i = size;i < num.size();++i){
			maxInWindows.push_back(num[index.front()]);
			while(!index.empty() && num[i] >=num[index.back()])
				index.pop_back();
			if(!index.empty() && index.front()<= int(i - size))
				index.pop_front();
			index.push_back(i);
		}
		maxInWindows.push_back(num[index.front()]);
	}
	return maxInWindows;
}



void Test(){
	int a[8] = {2,3,4,2,6,2,5,1};
//int a[4] = {2,5,4,7};
	vector<int> vec(a,a+8);
	vector<int> iv;
	iv = maxInWindows1(vec,3);
	for(vector<int>::iterator iter = iv.begin();iter != iv.end();++iter)
		cout<<*iter<<"\t";
}