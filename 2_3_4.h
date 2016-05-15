#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//替换空格
char* replace(char* str)
{
	if (str == NULL)
		return NULL;
	int count = 0; int i = 0;
	for (; str[i] != '\0'; ++i)
	{
		if ((str[i]) == ' ')
			count++;
	}
	i = i + 1;
	int tmp = i + 2 * count;
	if (tmp == i)
		return NULL;
	//(*str) = (char*)realloc((*str), sizeof(char)*(tmp));//是因为当str1为常量指针，而str3只是个指针变量不能重新分配空间
	char* str1 = (char*)malloc(sizeof(char)*(tmp));
	if (!str1)
		return NULL;
	tmp = tmp - 1;
	i = i - 1;
	while (i >= 0)// 注意这里一定不要访问越界，否则将出现无法析构数组的情况
	{
		if (str[i] != ' ')
			str1[tmp--] = str[i--];
		else
		{
			str1[tmp--] = '0';
			str1[tmp--] = '2';
			str1[tmp--] = '%';
			i--;
		}
	}
	return str1;

}
void replaceSpace(char *str,int length) {
        if(str == NULL)
            return;
        int count = 0;
        int len = 0;
        for(;str[len] != '\0';++len){
            if(str[len] == ' ')
                count++;
        }
        char* newstr = new char[count * 2 + length +1];
        if(!newstr)
            return;
        len = length;
		int j = count*2 + length;
		while(j >= 0){
            if(str[len] != ' ')
                newstr[j--] = str[len--];
            else{
                newstr[j--] ='0';
                newstr[j--] = '2';
                newstr[j--] = '%';
                len--;
            }
        }
        strcpy(str,newstr);
	}


void Test()
{
	char str1[] = "hello world may";//str1是个常量
	char str2[] = "hello world";
	char* str3 = "hello world";//str3里面的内容是常量
	char* str4 = "hello world";

	replaceSpace(str2,11);

	char* str5 = NULL;
	str5 = replace(str1);
	printf("str: %s\n", str2);
	free(str5);
	str5 = NULL;
	if (str1 == str2)
		printf("str1 and str2 are same.\n");
	else
		printf("str1 and str2 are not same.\n");
	if (str3 == str4)
		printf("str3 and str4 are same.\n");
	else
		printf("str3 and str4 anr not same.\n");
}