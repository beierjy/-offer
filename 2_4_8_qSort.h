#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//随机的快速排序算法
size_t partition(int* a, size_t low,size_t hight){
	if (a != NULL && low >= 0 && hight >= low)
	{
		int temp = a[hight];
		size_t i = low;
		for (int j = low; j < hight;j++)
		{
			if (a[j] < temp)
				Swap(a[i++], a[j]);
		}
		Swap(a[i], a[hight]);
		return i;
	}	
}
int Partition(int* data, int start, int end){
	if (data != NULL && start >= 0 && end >= start){
		srand(time(NULL));
		int index;
		index =( rand() % (end - start)) + start;
		Swap(data[end], data[index]);
		int small = start - 1;
		for (index = start; index < end; ++index)
		{
			if (data[index] <= data[end]){//以最后位置的数为分割点
				++small;
				if (small != index)
					Swap(data[index], data[small]);
			}
		}
		++small;
		Swap(data[small], data[end]);
		return small;
	}
}
void quicksort(int* a,int start,int end){
	int part;
	if (start < end){
		part = Partition(a, start, end);
		quicksort(a, start, part - 1);
		quicksort(a, part + 1, end);
	}
}
//年龄排序，算法的复杂度为O(n)
void sortAges(int* Age, int length)
{
	if (Age == NULL || length < 0)
		return;
	const int oldestAge = 99;
	int* timesOfAges = (int*)calloc(oldestAge + 1, sizeof(int));
	for (int i = 0; i < length; ++i)
	{
		int age = Age[i];
		timesOfAges[age]++;
	}
	int index = 0;
	for (int i = 0; i < oldestAge; i++)
	{
		for (int j = 0; j < timesOfAges[i]; j++){
			Age[index++] = i;
		}
	}
}

//寻找最小旋转数组的最小值
int Min(int* number, int length){
	if (number == NULL || length <= 0){
		perror("invalid array");
	}
	else{
		int p1 = 0; int p2 = length - 1;
		int mid = p1;
		while (number[p1] >= number[p2]){
			if (p2 - p1 == 1)
			{
				mid = p2;
				break;
			}
			mid = (p1 + p2) / 2;
			if (number[p1] == number[p2] &&
				number[p1] == number[mid])
			{	
				mid = p1;
				for (int i = p1; i <= p2; ++i){
					if (number[i] < number[mid])
						mid = i;
				}
				break;
			}
			if (number[p1] <= number[mid])
				p1 = mid;
			if (number[p2] >= number[mid])
				p2 = mid;
		}
		return number[mid];
	}
}
void Test()
{
	int a[] = { 1, 1, 1, 1, 1,1, 1, 1, 0};
	//size_t p = Partition(a, 0, 8);
	//quicksort(a, 0, 8);
	//sortAges(a, 9);
	//printf("%d", p);
	int x = Min(NULL, 9);
	printf("%d\n", x);
	///*for (int i = 0; i < 9; i++)
	//	printf("%d  ", a[i]);*/
}
