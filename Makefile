BubbleSort: BubbleSort.o
	$(CC) $(LDFLAGS) BubbleSort.o -o BubbleSort
StraightInsertSort: StraightInsertSort.o
	$(CC) $(LDFLAGS) StraightInsertSort.o -o StraightInsertSort


StraightInsertSort.o: StraightInsertSort.c
	$(CC) $(CFLAGS) -c StraightInsertSort.c
BubbleSort.o: BubbleSort.c
	$(CC) $(CFLAGS) -c BubbleSort.c	
clean:
	rm -rf *.o BubbleSort  StraightInsertSort *~
