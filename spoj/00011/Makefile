CC = g++
CFLAGS = -g -O2
OBJECTS = main.o

main : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o main && rm $(OBJECTS)

%.o : %.cpp
	ctags *.cpp -R && $(CC) $(CFLAGS) -c $<

clean:
	rm $(OBJECTS)
