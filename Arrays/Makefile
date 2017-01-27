TARGET = main
IDIR =./include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11
BIN = ./bin
SRC = ./src

ODIR=./obj
LDIR =./lib

_DEPS = ctci.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = q1.o q2.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRC)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN)/$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
