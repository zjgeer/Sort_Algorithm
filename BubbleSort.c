// suanfa1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include "stdlib.h"
#include "stdio.h"
#include "time.h"


/* ������������������ֵ�����Ը�����Ҫ�޸� */
#define MAXSIZE 1000
/* �������ݵĽṹ�� */
typedef struct
{
	int r[MAXSIZE + 1];	/* �洢�������� */
	int length;			/* ���ڼ�¼˳���ĳ��� */
}sqList;

void swap(sqList *L,int i,int j)
{
	int temp = L->r[i];

	L->r[i] = L->r[j];
	L->r[j] = temp;
}

int myrand()
{
	srand( (unsigned)time( NULL ) ); /*����ǰʱ�����ó�������������ӣ�����ÿ�β�����������һ��*/
	return rand();
}



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

//ð���������������

int main(int argc, char* argv[])
{
	int counter;
	srand( (unsigned)time( NULL ) ); /*����ǰʱ�����ó�������������ӣ�����ÿ�β�����������һ��*/
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

