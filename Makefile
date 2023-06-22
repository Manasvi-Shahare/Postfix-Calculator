project: stack.o token.o function.o main.o
	cc stack.o token.o function.o main.o -o project -lm
stack.o: stack.c stack.h
	cc -c stack.c
function.o: function.c function.h token.h
	cc -c function.c
main.o: main.c function.h token.h stack.h
	cc -c main.c 
token.o: token.c
	cc -c token.c
