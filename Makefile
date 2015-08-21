CC = gcc
BubbleSort: BubbleSort.o
	$(CC) $(LDFLAGS) BubbleSort.o -o BubbleSort
SelectSort: SelectSort.o
	$(CC) $(LDFLAGS) SelectSort.o -o SelectSort
StraightInsertSort: StraightInsertSort.o
	$(CC) $(LDFLAGS) StraightInsertSort.o -o StraightInsertSort
	
BubbleSort.o: BubbleSort.c
	$(CC) $(CFLAGS) -c BubbleSort.c	

SelectSort.o: SelectSort.c
	$(CC) $(CFLAGS) -c SelectSort.c	
	
StraightInsertSort.o: StraightInsertSort.c
	$(CC) $(CFLAGS) -c StraightInsertSort.c

clean:
	rm -rf *.o BubbleSort SelectSort StraightInsertSort *~
