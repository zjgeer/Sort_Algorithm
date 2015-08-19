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
		if(j < m && L->r[j] < L->r[j + 1])	/* ������������������ж��������һ�� */
		{
			++j;
		}
		
		if(temp >= L->r[j])					/* �жϸ��ڵ�������������С */
		{
			break;							/* ������ѵĶ��壬�����˳����� */
		}
		L->r[s] = L->r[j];					/* �����ֵ��ֵ���Ѷ� */
		s = j;
	}
	L->r[s] = temp;							/* ����Сֵ��ֵ������ */
}

void HeapSort(sqList *L)
{
	int i;

	for(i = L->length/2;i > 0;i--)			/* ������Ԫ�ص���Ϊ�󶥶� */
	{
		HeapAdjust(L,i,L->length);
	}

	for(i = L->length;i > 1;i--)			/* ȡ���󶥶ѵĶѶ���������β�����µ���ʣ���Ϊ�󶥶� */
	{
		Swap(L,1,i);
		HeapAdjust(L,1,i-1);
	}
}


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

