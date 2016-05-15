#include <iostream>
#include <vector>
using namespace std;

bool checkMoreThanHalf(vector<int>& numbers,int number){
        if(numbers.size() == 0)
            return false;
        int num = 0;
		for(vector<int>::iterator iter= numbers.begin();iter != numbers.end();++iter){
            if(*iter == number)
            	num ++;
		}
        if(num * 2 >= numbers.size())
            return true;
            else
            return false;        
    }
int partition(vector<int>& numbers,int begin,int end){
    if(numbers.size() == 0 || begin < 0 || end < 0)
        return 0;
    int part = numbers[begin];
    int i = end;int j = end;
    while(j > begin){
       if(numbers[j] >= part){
           int temp = numbers[j];
           numbers[j] = numbers[i];
           numbers[i] = temp; 
		   i--;
       }
       j--;
    }
    numbers[begin] = numbers[i];
    numbers[i] = part;
    return i;
}
int MoreThanHalfNumber(vector<int>& numbers){
    if(numbers.size() == 0){
        return 0;
    }
    int middle = numbers.size()>>1;
    int start = 0;
    int end = numbers.size() - 1;
    int index = partition(numbers,start,end);
    while(index != middle){
		if(index > middle){
			end = index - 1;
			index = partition(numbers,start,end);
		}
		else{
			start = index + 1;
            index = partition(numbers,start,end);
		}
    }
    int result = numbers[middle];
    if(!checkMoreThanHalf(numbers,result))
        result = 0;
    return result;
}
int MoreThanHalfNum_Solution(vector<int> numbers) {
    if(numbers.size() <= 0){
        return 0;
    }
    int result = MoreThanHalfNumber(numbers);
    return result;
    
}
 int MoreThanHalfNum_Solution1(vector<int> numbers) {
        if(numbers.size() == 0)
            return 0;
        int num = 1;
        int pre = *(numbers.begin());
        for(vector<int>::iterator iter = numbers.begin() + 1;iter != numbers.end();++iter){
            if(*iter == pre){
              ++num;
            }
            else{
                --num;
                if(num <= 0){
                    pre = *iter;
                    num = 1;
                }
            }
        }
        if(num >= 1){
            int nums = 1;
            for(vector<int>::iterator iter = numbers.begin() + 1;iter != numbers.end();++iter){
                if(*iter == pre)
                    nums++;
            }
            if(nums * 2 < numbers.size())
                return 0;
        }
        return pre;
    }

void Test(){
	int a[9] = {2,2,2,2,2,1,3,5,4};
	vector<int> vec(a,a+9);
	int b = MoreThanHalfNum_Solution1(vec);
	cout<<b;
}