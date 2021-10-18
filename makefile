all: work10.o
	gcc -o work10 work10.o
	
work10.o: work10.c
	gcc -c work10.c
	
run:
	./work10

clean:
	rm *.o
	