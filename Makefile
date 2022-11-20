CC=gcc
CFLAGS=-Wall

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ssdb: src/main.o
	$(CC) -o out/bin/sserv src/main.o 
clean:
	-rm src/*.o 