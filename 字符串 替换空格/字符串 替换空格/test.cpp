#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
void ReplaceBlank(string &str,int len)
{
	if (len < 0)
		return;
	int blankcount = 0;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == ' ')
		{
			++blankcount;//统计字符中空格个数
		}	
	}
	int newlength = len + blankcount * 2;//求新字符串中的长度
	if (newlength == len)
		return;
	int oldIndex = len - 1;//指向原始字符串结尾
	int newIndex = newlength - 1;//指向新的字符串结尾
	str.resize(newlength);//将字符串的容量一次性扩到新的大小 
	while (oldIndex>=0 && newIndex > oldIndex)
	{
		if (str[oldIndex] == ' ')
		{
			str[newIndex--] = '0';
			str[newIndex--] = '2';
			str[newIndex--] = '%';
		}
		else
		{
			str[newIndex--] = str[oldIndex];
		}
		--oldIndex;
	}
}
int main()
{
	string  str = "hello world";
	int len = str.size();
	ReplaceBlank(str, len);
	cout << str << endl;
	system("pause");
	return 0;
}




