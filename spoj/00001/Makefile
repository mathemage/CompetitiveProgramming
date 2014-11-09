CC = g++
CFLAGS = -g -O2
OBJECTS = main.o

debordeliser : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o debordeliser && rm $(OBJECTS)

%.o : %.cpp
	ctags *.cpp -R && $(CC) $(CFLAGS) -c $<

clean:
	rm $(OBJECTS)
