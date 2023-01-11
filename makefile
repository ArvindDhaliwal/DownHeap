all : A4
A4: A4.c
	gcc -Wall -std=c99 -pedantic A4.c -o A4
clean:
	rm *.o A4