#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int> > vec;
	if(sum < 3)
		return vec;
	int small = 1;int big = 2;
	while(small <= ((sum + 1) /2)){
		vector<int> ivec;int currsum = 0;
		for(int i =  small;i <= big;++i){
			currsum += i;
		}
		if(currsum == sum){
			for(int i = small;i<= big;++i){
				ivec.push_back(i);
			}
			vec.push_back(ivec);
		}
		else if(currsum < sum){
			++big;
			continue;
		}
		++small;
	}
	return vec;
}
void Test(){
    int sum = 15;
    vector<vector<int> >vec;
    vec = FindContinuousSequence(sum);
	for(vector<vector<int> >::iterator iter = vec.begin();iter != vec.end();++iter)
	{
		for(vector<int>::iterator iter1 = (*iter).begin();iter1 != iter->end();++iter1){
			cout<<*iter1<<" ";
		}
		cout<<endl;
	}
}
