sig: main.o error.o apue.h
		gcc  -o  sig main.o error.o 
main.o: 	main.c
		gcc -c main.c  
error.o:	error.c	apue.h
		gcc -c error.c

clean:
		rm error.o
		rm main.o
