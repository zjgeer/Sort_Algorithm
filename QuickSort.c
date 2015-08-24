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
/* 交换顺序表L中子表的记录，使枢轴记录到位，并返回其所在位置 */
/* 此时在它之前(后)的记录均表示不大(小)于它。 */
int Partition(sqList *L,int low,int high)
{
	int pivotkey;
	
	pivotkey = L->r[low];							/* 用子表的第一个记录作枢轴记录 */
	while(low < high)								/* 从表的两端交替向中间扫描 */
	{
		while(low < high && L->r[high] >= pivotkey)
		{
			high--;
		}
		Swap(L,low,high);							/* 将此枢轴记录小的记录交换到低端 */
		while(low < high && L->r[low] <= pivotkey)
		{
			low++;
		}
		Swap(L,low,high);							/* 将此枢轴记录大的记录交换到低端 */
	}
	return low;
}
/* 对顺序表L中的子序列L->r[low..high]作快速排序 */
void QSort(sqList *L,int low,int high)
{
	int pivot;
	
	if(low < high)
	{		
		pivot = Partition(L,low,high);				/* 将L->r[low..high]一分为二 */
													/* 算出枢轴值pivot */
		QSort(L,low,pivot - 1);						/* 对低子表进行排序 */
		QSort(L,pivot + 1,high);					/* 对高子表进行排序 */
	}
}

void QuickSort(sqList *L)
{
	/* 从数组下标1到下标为length */
	QSort(L,1,L->length);
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
	
	QuickSort(&myList);
	
	for(i = 0;i <= myList.length;i++)
	{
		printf("%d--%d  ",i,myList.r[i]);
	}
	printf("\n");
	
	return 0;
}
