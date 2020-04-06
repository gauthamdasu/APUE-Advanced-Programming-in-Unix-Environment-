ls:	ls.o error.o
	gcc -o ls ls.o error.o

stdsandlmts.o:	stat.c	apue.h
		gcc -c ls.c

error.o:	error.c	apue.h
		gcc -c error.c

clean:
		rm error.o
		rm ls.o
		rm a.out
