mpcalc: main.o error.o apue.h
		gcc  -o  mpcalc main.o error.o -lm   
main.o: 	main.c
		gcc -c main.c  
error.o:	error.c	apue.h
		gcc -c error.c

clean:
		rm error.o
		rm main.o
