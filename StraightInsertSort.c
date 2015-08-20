#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 10

typedef struct
{
	int r[MAXSIZE];
	int length;
}sqList;

void StraightInsertSort(sqList *L)
{
	int i,j;
	for(i = 2;i <= L->length;i++)
	{
		if(L->r[i] < L->r[i - 1])
		{
			L->r[0] = L->r[i];	
			for(j = i - 1;L->r[j] > L->r[0];j--)
			{
				L->r[j + 1] = L->r[j];
			}		
			L->r[j + 1] = L->r[0];
		}
	}
}

int main(int argc,char *argv[])
{
	int i;

	sqList myList;
	
	srand((unsigned)time(NULL));
	myList.length = MAXSIZE - 1;
	myList.r[0] = 0;
	for(i = 1;i <= myList.length;i++)
	{
		myList.r[i] = rand() % 100;
	}
	
	StraightInsertSort(&myList);
	
	for(i = 0;i < MAXSIZE;i++)
	{
		printf("%d--%d  ",i,myList.r[i]);	
	}
	printf("\n");
	return 0;
}
