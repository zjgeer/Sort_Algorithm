// SortAlgroithm: Defines the entry point for the console application.
// sort algroithm : 冒泡排序，简单选择排序，直接插入排序，希尔排序，堆排序，归并排序，快速排序
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/* 用于排序数组个数最大值，可以根据需要修改 */
#define MAXSIZE 10
/* 排序数据的结构体 */
typedef struct
{
	int r[MAXSIZE + 1];	/* 存储排序数组 */
	int length;			/* 用于记录顺序表的长度 */
}sqList;

void swap(sqList *L,int i,int j)
{
	int temp = L->r[i];

	L->r[i] = L->r[j];
	L->r[j] = temp;
}

int myrand()
{
	srand( (unsigned)time( NULL ) ); /*将当前时间设置成随机函数的种子，所以每次产生的数都不一样*/
	return rand();
}


/* 最易想到的冒泡排序算法 */
void BubbleSort0(sqList *L)
{
	int i,j;
	float swCounter = 0;

	for(i = 0;i < L->length - 1;i++)
	{
		for(j = i + 1;j < L->length;j++)
		{
			if(L->r[i] > L->r[j])
			{
				swap(L,i,j);
				swCounter ++;
			}
		}
	}
	printf("\nThe bubbleSort0 swap counter is %f.\n",swCounter);
}

void BubbleSort1(sqList *L)
{
	int i,j;
	float swCounter1 = 0;
	char flag = 1;

	for(i = 0; i < L->length && flag;i++)
	{
		flag = 0;
		for(j = L->length-2;j >= i;j--)
		{
			if(L->r[j] > L->r[j+1])
			{
				swap(L,j,j+1);
				swCounter1 ++;
				flag = 1;
			}
		}
	}

	printf("\nThe bubbleSort1 swap counter is %f.\n",swCounter1);
	
}


void SelectSort(sqList *L)
{
	int i,j,min;
	float swCounter = 0;
	for(i = 0;i < L->length - 1;i++)
	{
		min = i;

		for(j = i+1;j < L->length;j++)
		{
			if(L->r[min] > L->r[j])
			{
				min = j;
			}
		}
		if(i != min)
		{
			swap(L,i,min);
			swCounter++;

		}
	}
	printf("\nThe SelectSort swap counter is %f.\n",swCounter);
}

//冒泡排序的两个方法

int main(int argc, char* argv[])
{
	int counter;
	srand( (unsigned)time( NULL ) ); /*将当前时间设置成随机函数的种子，所以每次产生的数都不一样*/
	sqList mysqList,mysqList1;
	
	mysqList.length = MAXSIZE;
	mysqList1.length = MAXSIZE;


	for(counter = 0;counter<mysqList.length;counter++)
	{
		mysqList.r[counter] = rand();
		mysqList1.r[counter] = mysqList.r[counter];
	}



	printf("\nThe original data is :\n");	
	for(counter = 0;counter < mysqList.length;counter++)
	{

		printf("%d: %d \n",counter,mysqList.r[counter]);
	}

	BubbleSort0(&mysqList);
//	BubbleSort1(&mysqList1);
	SelectSort(&mysqList1);

/*	printf("\nThe bubble sort result is :\n");	
	for(counter = 0;counter < mysqList.length;counter++)
	{

		printf("%d: %d \n",counter,mysqList.r[counter]);
	}

	printf("\nThe Simple sort result is :\n");	
	for(counter = 0;counter < mysqList1.length;counter++)
	{

		printf("%d: %d \n",counter,mysqList1.r[counter]);
	}
*/
	return 0;
}

