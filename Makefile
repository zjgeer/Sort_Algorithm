CC = gcc
BubbleSort: BubbleSort.o
	$(CC) $(LDFLAGS) BubbleSort.o -o BubbleSort
SelectSort: SelectSort.o
	$(CC) $(LDFLAGS) SelectSort.o -o SelectSort
StraightInsertSort: StraightInsertSort.o
	$(CC) $(LDFLAGS) StraightInsertSort.o -o StraightInsertSort
ShellSort: ShellSort.o
	$(CC) $(LDFLAGS) ShellSort.o -o ShellSort
MergeSort: MergeSort.o
	$(CC) $(LDFLAGS) MergeSort.o -o MergeSort
QuickSort: QuickSort.o
	$(CC) $(LDFLAGS) QuickSort.o -o QuickSort	
	
BubbleSort.o: BubbleSort.c
	$(CC) $(CFLAGS) -c BubbleSort.c	

SelectSort.o: SelectSort.c
	$(CC) $(CFLAGS) -c SelectSort.c	
	
StraightInsertSort.o: StraightInsertSort.c
	$(CC) $(CFLAGS) -c StraightInsertSort.c
	
ShellSort.o: ShellSort.c
	$(CC) $(CFLAGS) -c ShellSort.c	

MergeSort.o: MergeSort.c
	$(CC) $(CFLAGS) -c MergeSort.c	

QuickSort.o: QuickSort.c
	$(CC) $(CFLAGS) -c QuickSort.c	

clean:
	rm -rf *.o *~ *.exe BubbleSort SelectSort StraightInsertSort ShellSort MergeSort QuickSort 
