# CC for the compiler name
# CFLAGS for the compiler options
# OBJS is a list of all object files
CC=g++
CFLAGS=-c 
OBJS=main.o collections.o stocks.o functions.o
INCLUDES=stocks.h collections.h functions.h

prog: $(OBJS) 
	$(CC) $(OBJS) -o prog
    
%.o: %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) $<;
    
clean:
	rm *.o prog