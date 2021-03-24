
CC = g++
CFLAGS = -Wall -c -g
OFLAGS = -o
INCLUDE= -I../inc/
HEADER = ../inc/
SRC = ../src/
OBJ = ../obj/
BIN = ../bin/


$(BIN)mapoperation : $(OBJ)main.o $(OBJ)utility.o
	$(CC) $(OFLAGS) mapoperation  $(OBJ)main.o $(OBJ)utility.o
	mv mapoperation $(BIN)

$(OBJ)utility.o: $(SRC)utility.cpp $(HEADER)header.h
	$(CC) $(CFLAGS) $(SRC)utility.cpp $(INCLUDE)
	mv utility.o $(OBJ)

$(OBJ)main.o: $(SRC)main.cpp $(HEADER)header.h
	$(CC) $(CFLAGS) $(SRC)main.cpp $(INCLUDE)
	mv main.o  $(OBJ)

clean:
	rm -rf $(BIN)mapoperation
	rm -rf $(OBJ)*.o




