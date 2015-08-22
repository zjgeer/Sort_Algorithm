#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 20

typedef struct
{
	int r[MAXSIZE];
	int length;
}sqList;

/* 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n] */
void Merge(int SR[],int TR[],int i,int m,int n)
{
	int j,k;
	/* 将SR中记录由小到大归并入TR */
	for(j = m + 1,k = i;i <= m && j <= n;k++)
	{
		if(SR[i] < SR[j])
		{
			TR[k] = SR[i++];
		}
		else
		{
			TR[k] = SR[j++];
		}
	}
	/* 判断如果序列的前半部分是否排完 */
 	while(i <= m)
	{
		TR[k++] = SR[i++];		/* 将剩余的序列复制到TR中 */
	} 
	/* 判断如果序列的后半部分是否排完*/	
 	while(j <= n)
	{
		TR[k++] = SR[j++];		/* 将剩余的序列复制到TR中 */
	} 
}

/* 将SR[s..t]归并排序为TR1[s..t] */
void MSort(int SR[],int TR1[],int s,int t)
{
	int m;
	int TR2[MAXSIZE + 1];
	if(s == t)
	{
		TR1[s] = SR[s];
	}
	else
	{
		/* 将SR[s..t]平分为SR[s..m]和SR[m+1..t] */
		m = (s + t) / 2;
		/* 递归将SR[s..m]归并为有序的TR2[s..m] */
		MSort(SR,TR2,s,m);
		/* 递归将SR[m+1..m]归并为有序的TR2[m+1..t] */
		MSort(SR,TR2,m + 1,t);
		/* 将TR2[s..m] 与TR2[m+1..t]归并到TR1[s..t] */
		Merge(TR2,TR1,s,m,t);
	}
}

/* 对顺序表L做归并排序 */
void MergeSort(sqList *L)
{
	MSort(L->r,L->r,1,L->length);
}

int main(int argc, char *argv[])
{
	int i;
	sqList myList;

	srand((unsigned)time(NULL));
	
	myList.length = MAXSIZE - 1;
	
	myList.r[0] = 0;
	
	for( i = 1;i < MAXSIZE;i++)
	{
		myList.r[i] = rand() % 100;
	}
	for(i = 0;i < MAXSIZE;i++)
	{
		printf("%d--%d  ",i,myList.r[i]);
	}
	printf("\n");
	
	MergeSort(&myList);

	printf("The merge sort result is :\n");

	for(i = 0;i < MAXSIZE;i++)
	{
		printf("%d--%d  ",i,myList.r[i]);
	}
	printf("\n");
	return 0;
}



