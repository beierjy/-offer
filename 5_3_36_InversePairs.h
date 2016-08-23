/*在数组中的两个数字，
如果前面一个数字大于后面的数字，
则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。
并将P对1000000007取模的结果输出。 即输出P%1000000007
*/
//利用归并排序的思想
#include <iostream>
#include <cstdlib>

using namespace std;
int MergeCount(int*,int*,int*,int*,int*);
int Inverse(int* numbers,int start,int last){
    if(numbers == NULL || start < 0 || last < 0)
        return 0;
    if(last - start == 1){
            if(numbers[last] < numbers[start]){
                int temp = numbers[last];
                numbers[last] = numbers[start];
                numbers[start] = temp;
                return 1;
            }
                else{
                    return 0;
                }
    }
    int mid = (start + last) / 2;
    int left = Inverse(numbers,0,mid);
    int right = Inverse(numbers,mid + 1,last);
    int mergecount = MergeCount(numbers,&numbers[0],&numbers[mid],&numbers[mid + 1],&numbers[last]);
    return left + right + mergecount;
}
int MergeCount(int* numbers,int* start1,int*p,int*start2,int*q){
	if(numbers == NULL || p== NULL ||q == NULL||start1 == NULL||start2==NULL)
	return 0;
	int len = q - start1 + 1;
	int* c = new int[len];
	int counts = 0;int pos = len - 1;
	int* temp = p;
	while(p >= start1 && q >= start2){
	    if(*p > *q){
	        c[pos--] = *p;
	        counts += q - start2 + 1;
	        p--;
	    }
	    else{
	        c[pos--] = *q;
	        q--;
	    }
	}
	while(q >= start2){
		c[pos--] = *q;
		q--;
	}
	while(p >= start1){
		c[pos--] = *p;
		p--;
	}
	for(int i = 0;i < len;++i){
		*start1 = c[i];
		++start1;
	}
	delete[] c;
	return counts;
}

void Test(){
    int a[4] = {7,5,6,4};
    int c;
    c = Inverse(a,0,3);
    cout<<c<<endl;
}

