//多维背包问题

#include "stdafx.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
 
int array[64][6];

int worth[6];

int property[10][6] = { { 8,12,13,64,22,41 },
{ 8, 12, 13, 75 ,22 ,41 },
{ 3, 6, 4, 18 ,6, 4 } ,
{ 5, 10, 8, 32, 6, 12 },
{ 5, 13, 8, 42, 6 ,20 },
{ 5, 13, 8, 48, 6, 20 },
{ 0, 0, 0,0, 8,0 },
{ 3, 0, 4,0, 8,0 },
{ 3, 2, 4,0, 8,4 },
{ 3, 2, 4,8, 8,4 } };

int restraint[10];

int x[] = { 0,0,0,0,0,0 };

int result[10] = { 0,0,0,0,0,0,0,0,0,0 };

int outArry[6] = { 0,0,0,0,0,0 };

int MaxWorth = 0;

//找最大值
int max(int a, int b);
//二进制数据转换
int* IntToBiary(int num);
//创建数组
void createArray();
//初始化物品属性价格 
void initData(void);
//清除缓存
void ClearArray(void);

int main()
{
	initData();

	createArray();
	for (int i = 0; i < 64;i++)
	{
		int sumWorth = 0;
		ClearArray();
		int n = 0;
		for (int j = 0; j < 10;j++)
		{
			for (int k = 0; k < 6;k++)
			{
				if (array[i][k] == 1)
				{
					result[j] += property[j][k];
				}
				else if (array[i][j] == 0)
				{
					result[j] += 0;
				}
			}
		}
		if (result[0] < restraint[0] &&
			result[1] < restraint[1] &&
			result[2] < restraint[2] &&
			result[3] < restraint[3] &&
			result[4] < restraint[4] &&
			result[5] < restraint[5] &&
			result[6] < restraint[6] &&
			result[7] < restraint[7] &&
			result[8] < restraint[8] &&
			result[9] < restraint[9]
			)
		{
			for (int k = 0;k < 6;k++)
			{
				if (array[i][k] == 1)
				{
					sumWorth += worth[k];
					outArry[k] = 1;
				}
				else
				{
					outArry[k] = 0;
				}
			}
		}
		else
		{
			sumWorth = 0;
		}
		if (MaxWorth < sumWorth)
		{
			MaxWorth = sumWorth;
			x[0] = outArry[0];
			x[1] = outArry[1];
			x[2] = outArry[2];
			x[3] = outArry[3];
			x[4] = outArry[4];
			x[5] = outArry[5];
		}
	}
	printf("产品价值：\n");
	for (int i = 0;i < 6;i++)
	{
		printf("  %d\n", worth[i]);
	}

	printf("最优解：%d %d %d %d %d %d \n", x[0], x[1], x[2], x[3], x[4], x[5]);
	MaxWorth = 0;

	printf("最优解的价值：\n");
	for (int i = 0;i < 6;i++)
	{
		if (x[i] == 1)
		{
			printf("  %d  ", worth[i]);
			MaxWorth +=worth [i];
		}
	}
	printf("最优值：%d \n", MaxWorth);
	system("pause");
	return 0;
}

void initData(void)
{
	memset(worth, 0, sizeof(worth[6]));

	memset(property, 0, sizeof(property[10][6]));

	memset(restraint, 0, sizeof(restraint[10]));

	printf("请分别输入物品价值： \n");
	for (int i = 0;i < 6;i++)
	{
		scanf("%d", &worth[i]);
	}

	printf("请分别输入物品属性： \n");
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0; j < 6;j++)
		{
			scanf("%d", &(property[i][j]));
		}
	}

	printf("请分别输入约束： \n");
	for (int i = 0;i < 10;i++)
	{
		scanf("%d", &restraint[i]);
	}
	
	memset(x, 0, sizeof(x[6]));

	memset(outArry, 0, sizeof(outArry[6]));

	MaxWorth = 0;

}
int* IntToBiary(int num)
{
	int b[16];
	char* arrary = "";
	int n = 0;
	for (int n = 0; num; num >>= 1, n++)
	{
		b[n] = num & 1;
	}
	return b;
}

void createArray()
{
	int b = 0;
	memset(array, 0, sizeof(array));
	for (int i = 0;i < 64;i++)
	{
		for (int j = 5, k = 0; j >= 0, k < 6;j--, k++)
		{
			int* arr = IntToBiary(i);
			array[i][j] = arr[k];
		}
	}

	for (int i = 0;i < 64;i++)
	{
		for (int j = 0; j < 6;j++)
		{
			if (array[i][j] != 1)
			{
				array[i][j] = 0;
			}
		}
	}
}




int max(int a, int b)
{
	return  a > b ? a : b;
}
void ClearArray(void)
{
	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	result[3] = 0;
	result[4] = 0;
	result[5] = 0;
	result[6] = 0;
	result[7] = 0;
	result[8] = 0;
	result[9] = 0;
	result[10] = 0;

	outArry[0] = 0;
	outArry[1] = 0;
	outArry[2] = 0;
	outArry[3] = 0;
	outArry[4] = 0;
	outArry[5] = 0;
}
