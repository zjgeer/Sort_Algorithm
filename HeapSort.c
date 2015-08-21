// HeapSort_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define MAXSIZE 10

typedef struct 
{
	int r[MAXSIZE];
	int length;
}sqList;

void Swap(sqList *L,int i,int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void HeapAdjust(sqList *L,int s,int m)
{
	int j,temp;

	temp = L->r[s];

	for(j = 2 * s;j <= m;j++)
	{
		if(j < m && L->r[j] < L->r[j + 1])	/* 如果左右子树都存在判断最大是哪一个 */
		{
			++j;
		}
		
		if(temp >= L->r[j])					/* 判断父节点与两个子树大小 */
		{
			break;							/* 已满足堆的定义，可以退出调整 */
		}
		L->r[s] = L->r[j];					/* 将最大值赋值给堆顶 */
		s = j;
	}
	L->r[s] = temp;							/* 将最小值赋值给子树 */
}

void HeapSort(sqList *L)
{
	int i;

	for(i = L->length/2;i > 0;i--)			/* 将数组元素调整为大顶堆 */
	{
		HeapAdjust(L,i,L->length);
	}

	for(i = L->length;i > 1;i--)			/* 取出大顶堆的堆顶，放在碓尾，重新调整剩余的为大顶堆 */
	{
		Swap(L,1,i);
		HeapAdjust(L,1,i-1);
	}
}
https://github.com/zjgeer/Sort_Algorithm.git

int main(int argc, char* argv[])
{
	int i;
	sqList myList;

	srand((unsigned)time(NULL));
	
	myList.length = MAXSIZE - 1;
	myList.r[0] = 0;
	
	for( i = 1;i <MAXSIZE;i++)
	{
		myList.r[i] = rand()%100;
	}

	HeapSort(&myList);

	printf("The heap sort result is :\n");

	for(i = 1;i < MAXSIZE;i++)
	{
		printf("%d=%d  ",i,myList.r[i]);
	}

	return 0;
}

