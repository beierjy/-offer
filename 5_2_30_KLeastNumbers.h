/*
输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，
则最小的4个数字是1,2,3,4,。
*/
#include <iostream>
#include <vector>
#include<algorithm>
#include <set>

//采用快速排序划分的方法，只适用于数组可以改变的情况
using namespace std;
void swap(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}
int partition(vector<int>& input,int begin,int end){
    int mid = (begin + end) >> 1;
    if(input[begin] < input[mid] && input[mid] <= input[end]){
        swap(input[begin],input[mid]);
    }
    else if(input[begin] < input[mid] && input[mid] > input[end]){
        swap(input[begin],input[end]);
    }
    int part = input[begin];
    int  i = begin;int j = begin + 1;
    while(j <= end){
		if(input[j] <= part){
			++i;
                swap(input[i],input[j]);
	}
        j++;
    }
    swap(input[i],input[begin]);
    return i;   
}
        
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> output;
	if(input.size() == 0)
		cout<<"Invalid input";
	int start = 0;int end = input.size() - 1;
	int p = partition(input,start,end);
	while( p != k-1){
		if(p > k - 1){
			end = p - 1;
			p = partition(input,start,end);
		}
		else{
			start = p + 1;
			p = partition(input,start,end);
		}
	}
	for(int i = 0;i < k;++i)
		output.push_back(input[i]);
    return output;   
}
//采用大根堆存储最小的k个数，时间复杂度为O(nlogk);
vector<int> GetLeastNumbers_Solution1(vector<int> input, int k) {
        vector<int> output; multiset<int,greater<int> > leastNumbers;
        if(k <= 0 || input.size() < k)
            return output;
        vector<int>::const_iterator iter = input.begin();
        for(;iter != input.end();++iter){
            if(leastNumbers.size() < k)
                leastNumbers.insert(*iter);
            else{
                 multiset<int,greater<int> >::iterator iterGreatest = leastNumbers.begin();
                if(*iter < *(leastNumbers.begin()))
                    {
                    leastNumbers.erase(iterGreatest);
                    leastNumbers.insert(*iter);
                }
            }      
        }
         multiset<int,greater<int> >::iterator iter1 = leastNumbers.begin();
        for(int i = 0; i< k;++i){
            output.push_back(*iter1);
            iter1++;
        }
        return output;
    }
void Test(){
	int a[8] = {4,5,6,7,1,3,8,2};
	vector<int> vec(a,a+8);
	vector<int> output(GetLeastNumbers_Solution1(vec,4));
	for(int i = 0; i< 4;++i)
		cout<<output[i]<<" ";
}
