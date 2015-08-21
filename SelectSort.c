#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

/* 简单选择排序算法，与冒泡排序类似 */
void SelectSort(sqList *L)
{
	int i,j,min;
	/* 从数组下标1开始 */
	for(i = 1;i < L->length;i++) 
	{
		min = i;		/* 将当前下标定义为最小值下标 */
		for(j = i + 1;j <= L->length;j++)	/* 依次与后面的数据比较 */
		{
				if(L->r[j] < L->r[min])		/* 如果有小于当前最小值的关键字 */
				{
					min = j;				/* 将此关键字的下标赋值给min */
				}
		}
		if(i != min)						/* 若min与i不相等，找到最小值交换 */
		{
			Swap(L,i,min);			
		}
	}
}

int main(int argc,int *argv[])
{
	int i;
	sqList myList;
	
	srand((unsigned)time(NULL));
	
	myList.length = MAXSIZE -1;
	
	myList.r[0] = 0;
	for(i = 1;i <= myList.length;i++)
	{
		myList.r[i] = rand() % 100;
	}
	SelectSort(&myList);
	
	for(i = 0;i <= myList.length;i++)
	{
		printf("%d--%d ",i,myList.r[i]);
	}
	
}






