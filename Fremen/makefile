Fremen: fremen.o tools.o socket.o communication.o
	gcc -o Fremen fremen.o tools.o socket.o communication.o -Wall -Wextra
fremen.o: fremen.c fremen.h tools.h communication.h socket.h
	gcc -c fremen.c -Wall -Wextra
tools.o: tools.c tools.h fremen.h communication.h socket.h
	gcc -c tools.c -Wall -Wextra
communication.o: communication.c tools.h fremen.h
	gcc -c communication.c -Wall -Wextra
socket.o: socket.c socket.h fremen.h tools.h
	gcc -c socket.c -Wall -Wextra
