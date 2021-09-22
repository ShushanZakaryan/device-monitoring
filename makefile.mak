CC=g++
CFLAGS=-I.
DEPS = device.h monitor.h
OBJ = device.o monitor.o

%.o: %.c $(DEPS)
        $(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
        $(CC) -std=c++2b-o $@ $^ $(CFLAGS)
