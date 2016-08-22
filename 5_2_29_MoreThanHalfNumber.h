/*数组中有一个数字出现的次数超过数组长度的一半，
请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，
超过数组长度的一半，因此输出2。如果不存在则输出0。
*/
#include <iostream>
#include <vector>
using namespace std;

//运用快速排序的划分的思想
bool g_bInputInvalid = false;
bool CheckInvalidArray(vector<int>& numbers){
	g_bInputInvalid = false;
	if(numbers.size()<=0)
		g_bInputInvalid = true;
	return g_bInputInvalid;
}

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
        else{
        	g_bInputInvalid = true;
            	return false;        
    	}
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
//统计最后个数不小于1的元素
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
