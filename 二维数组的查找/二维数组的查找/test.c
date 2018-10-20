#include<stdio.h>
int Find(int *arr, int ROW, int COL, int data)
{
	int row = 0;//定义行为0
	int col = COL - 1;//列为3
	if ((arr != NULL) && (ROW>0&&COL>0))//判断是否为空数组
	{
		while (row<ROW&&col >= 0)//直到排除完
		{
			if (arr[row*col + col] == data)//右上角为查找的数字
			{
				return 1;
			}
			else if (arr[col*row + col]>data)//右上角大于data，要剔除最后一列
			{
				--col;
			}
			else{
				row++;//右上角小于data，向下移动一行
			}
		}		
	}
	return 0;
}
int main()
{
	int arr[] = { 1,2,9,10,3,4,11,12,5,7,13,14,6,9,15,16};
	int data = 0;
	int ROW = 3;
	int COL = 3;
	printf("请输入你要查找的数字：");
	scanf_s("&data");
	int ret=Find(arr, ROW, COL, data);
	if (ret == 1)
	{
		printf("找到了\n");
	}
	else if (ret==0)
	{
		printf("找不到\n");
	}
	system("pause");
	return 0;
}

