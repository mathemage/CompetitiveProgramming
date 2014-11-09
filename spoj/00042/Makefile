CC = gcc
CFLAGS = -g -O1
OBJECTS = main.o

main : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o main && rm $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(OBJECTS)
