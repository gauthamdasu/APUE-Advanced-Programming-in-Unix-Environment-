a.out:	stat.o error.o
	gcc -o a.out stat.o error.o

stdsandlmts.o:	stat.c	apue.h
		gcc -c stat.c

error.o:	error.c	apue.h
		gcc -c error.c

clean:
		rm error.o
		rm stat.o
		rm a.out
