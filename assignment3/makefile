.PHONY: directories clean
CC=g++
CFLAGS=-std=c++11
LIBS=-lgtest -lpthread
OBJ=obj
BIN=bin
SRC=src
TEST=test
OUTPUT=test_output
TEST_FILES=$(TEST)/ut_shape.cpp $(TEST)/ut_picture.h $(TEST)/ut_iterator.h
SRC_FILES= $(SRC)/circle.h $(SRC)/shape.h $(SRC)/rectangle.h $(SRC)/read_input.h $(SRC)/sort.h $(SRC)/triangle.h $(SRC)/picture.h $(SRC)/iterator.h $(SRC)/iterator.cpp $(SRC)/find.h
GEO=$(SRC)/geo.cpp

all: directories $(BIN)/ut_all
	$(BIN)/ut_all

$(BIN)/ut_all: $(OBJ)/ut_shape.o $(OBJ)/iterator.o
	$(CC) $(CFLAGS) -Wfatal-errors -o $@ $(OBJ)/iterator.o $< $(LIBS)

$(BIN)/geo: $(OBJ)/geo.o
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

$(OBJ)/iterator.o: $(SRC)/iterator.cpp $(SRC)/iterator.h
	$(CC) $(CFLAGS) -Wfatal-errors -c $< -o $@

$(OBJ)/ut_shape.o: $(TEST_FILES) $(SRC_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/geo.o: $(GEO) $(SRC_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p $(OBJ) $(BIN) $(OUTPUT)

clean:
	rm -rf $(OBJ) $(BIN) $(OUTPUT)

stat:
	wc $(SRC)/* $(TEST)/*
