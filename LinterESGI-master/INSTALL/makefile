DEBUG=yes
CC=gcc
EXEC=../bin/Template
SRC= $(wildcard ../sources/*)
OBJ= $(wildcard ../bin/*.o)
LIB= $(wildcard ../ext/*)

all: $(EXEC)

create: $(OBJ)
	$(CC) -o $(EXEC) $(SRC)

.PHONY: clean mrproper

clean:
	rm -rf $(OBJ)

mrproper: clean
	rm -rf $(EXEC)
