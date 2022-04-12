Fremen: fremen.o tools.o socket.o communication.o mainFunctions.o
	gcc -o Fremen fremen.o tools.o socket.o communication.o mainFunctions.o -Wall -Wextra
fremen.o: fremen.c fremen.h tools.h communication.h socket.h mainFunctions.h
	gcc -c fremen.c -Wall -Wextra
tools.o: tools.c tools.h fremen.h communication.h socket.h mainFunctions.h
	gcc -c tools.c -Wall -Wextra
communication.o: communication.c tools.h fremen.h mainFunctions.h
	gcc -c communication.c -Wall -Wextra
socket.o: socket.c socket.h fremen.h tools.h mainFunctions.h
	gcc -c socket.c -Wall -Wextra
mainFunctions.o: mainFunctions.c mainFunctions.h fremen.h tools.h communication.h socket.h
	gcc -c mainFunctions.c -Wall -Wextra
