.PHONY: dirs clean stat
CC=g++
CFLAGS=-std=c++11
LIBS=-lgtest -lpthread
OBJ=obj
BIN=bin
TEST=test
SRC=src
UT=$(BIN)/ut_all
EXE=$(BIN)/main
VPATH=$(SRC)

objects=$(OBJ)/io.o $(OBJ)/item.o $(OBJ)/book.o $(OBJ)/collection_iterator.o $(OBJ)/collection.o $(OBJ)/iterator.o $(OBJ)/library.o
ut_objects=$(OBJ)/ut_all.o
UT_DEPS=$(TEST)/ut_book.h $(TEST)/ut_collection.h $(TEST)/ut_iterator.h $(TEST)/ut_library.h

all: dirs $(UT) $(EXE)
	$(UT)

$(EXE): $(OBJ)/main.o $(objects)
	$(CC) $(CFLAGS) -Wfatal-errors -o $@ $^

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CFLAGS) -Wfatal-errors -c -o $@ $<

$(UT): $(ut_objects) $(objects)
	$(CC) $(CFLAGS) -Wfatal-errors -o $(UT) $(ut_objects) $(objects) $(LIBS)

$(OBJ)/%.o: %.cpp %.h
	$(CC) $(CFLAGS) -Wfatal-errors -c -o $@ $<

$(OBJ)/%.o: $(TEST)/%.cpp $(UT_DEPS)
	$(CC) $(CFLAGS) -Wfatal-errors -c -o $@ $<

dirs:
	mkdir -p $(OBJ) $(BIN)

clean:
	rm -rf $(OBJ) $(BIN)

stat:
	wc $(SRC)/**/* $(TEST)/**/*
