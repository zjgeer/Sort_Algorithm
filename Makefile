BubbleSort: BubbleSort.o
	$(CC) $(LDFLAGS) BubbleSort.o -o BubbleSort

BubbleSort.o: BubbleSort.c
	$(CC) $(CFLAGS) -c BubbleSort.c	
clean:
	rm -rf *.o BubbleSort *~
