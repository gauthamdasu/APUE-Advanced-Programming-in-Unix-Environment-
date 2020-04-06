a.out:	telbook.o error.o
	gcc -o a.out telbook.o error.o

stdsandlmts.o:	telbook.c	apue.h
		gcc -c telbook.c

error.o:	error.c	apue.h
		gcc -c error.c

clean:
		rm error.o
		rm telbook.o
		rm a.out
