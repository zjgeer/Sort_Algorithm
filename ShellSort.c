#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 10

typedef struct
{
	int r[MAXSIZE];
	int length;
}sqList;

void ShellSort(sqList *L)
{
	int i,j;
	int increment = L->length;
	
	do
	{
		/* 增量序列 */
		increment = increment / 3 + 1;	
		for(i = increment + 1;i <= L->length;i++)
		{
			if(L->r[i] < L->r[i - increment])
			{
				/* 需要将L->r[i]插入有序增量表 */
				L->r[0] = L->r[i];	/* 暂存在L->r[0] */
				for(j = i - increment;j > 0 && L->r[0] < L->r[j];j -= increment)
				{
					/* 记录后移，查找插入位置 */
					L->r[j + increment] = L->r[j];
				}
				/* 插入 */
				L->r[j + increment] = L->r[0];
			}
		}
	}while(increment > 1);
}

int main(int argc,char *argv[])
{
	int i;
	sqList myList;
	
	srand((unsigned)time(NULL));
	
	myList.length = MAXSIZE -1;
	myList.r[0] = 0;
	for(i = 1;i <＝ myList.length;i++)
	{
		myList.r[i] = rand() % 10;
	}
	
	ShellSort(&myList);
	
	for(i = 0;i <= myList.length;i++)
	{
		printf("%d--%d  ",i,myList.r[i]);
	}
	printf("\n");
	
}