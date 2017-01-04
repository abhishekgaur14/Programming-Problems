TARGET = main
IDIR =./include
CC=g++
CFLAGS=-I$(IDIR)
BIN = ./bin
SRC = ./src

ODIR=./obj
LDIR =./lib

_DEPS = LinkedList.h linkedListUtils.h ctci.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = LinkedList.o main.o linkedListUtils.o q1.o q2.o q3.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRC)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN)/$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
