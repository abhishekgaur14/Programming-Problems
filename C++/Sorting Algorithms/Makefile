TARGET = sorting
IDIR =./include
CC=g++
CFLAGS=-I$(IDIR)
BIN = ./bin
SRC = ./src

ODIR=./obj
LDIR =./lib

_DEPS = arrayUtils.h sortingAlgos.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = sortingAlgos.o arrayUtils.o sorting.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRC)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN)/$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
