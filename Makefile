EXE = exec
OBJ_DIR = objetos
SRC_DIR = fontes
SRC = $(wildcard $(SRC_DIR)/*.cc)
CSRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)
COBJ = $(CSRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CXX = g++
CC = gcc
SQLFLAGS = -DSQLITE_THREADSAFE=0 -DSQLITE_OMIT_LOAD_EXTENSIONTARGET
CPPFLAGS = -std=c++11
CFLAGS = -g -Wall -pedantic
LDFLAGS =
LDLIBS = 

.PHONY: all clean sqlite

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@ objetos/sqlite3.o -lpthread -ldl

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(COBJ)

sqlite: $(COBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(SQLFLAGS) $(CFLAGS) -c $< -o $@