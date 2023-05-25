.PHONY: all clean test

CC = gcc
CCOPTS = -Wall -Wextra

all: simfs.a simfs_test 

simfs.a: image.o block.o inode.o free.o 
	ar rcs $@ $^

simfs_test: simfs_test.c simfs.a
	gcc -Wall -Wextra -DCTEST_ENABLE -o $@ $^

simfs_test.o: simfs_test.c
	gcc -Wall -Wextra -c $< -DCTEST_ENABLE

image.o: image.c
	$(CC) $(CCOPTS) -c $< -o $@

block.o: block.c
	$(CC) $(CCOPTS) -c $< -o $@

inode.o: inode.c
	$(CC) $(CCOPTS) -c $< -o $@

free.o: free.c
	$(CC) $(CCOPTS) -c $< -o $@

test: simfs_test
	./simfs_test

clean:
	rm -f *.o simfs.a simfs_test