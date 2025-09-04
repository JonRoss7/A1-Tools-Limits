# Compiler
CC = gcc
CFLAGS = -Wall -g

# Target executable
TARGET = words

# Object files
OBJS = main.o word_count.o map.o wc_sort.o ../recurse.o

all: $(TARGET)

# Link all object files into the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile main.c
main.o: main.c word_count.h
	$(CC) $(CFLAGS) -c main.c

# Compile word_count.c
word_count.o: word_count.c word_count.h
	$(CC) $(CFLAGS) -c word_count.c

# Compile map.c (from parent directory)
map.o: ../map.c
	$(CC) $(CFLAGS) -c ../map.c -o map.o

# Compile recurse.c (from parent directory)
../recurse.o: ../recurse.c
	$(CC) $(CFLAGS) -c ../recurse.c -o ../recurse.o

clean:
	rm -f *.o $(TARGET) ../recurse.o
