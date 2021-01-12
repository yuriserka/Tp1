EXE = exec
OBJ_DIR = bin
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.cc)
OBJ = $(SRC:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)
CXX = g++
CC = gcc
SQLFLAGS = -DSQLITE_THREADSAFE=0 -DSQLITE_OMIT_LOAD_EXTENSIONTARGET
CPPFLAGS = -std=c++11
CFLAGS = -g -Wall -pedantic
LDFLAGS =
LDLIBS = -Wl,--no-as-needed -ldl

.PHONY: all clean sqlite

all: create_bin_folder sqlite.o $(EXE)

create_bin_folder:
	@mkdir -p bin

$(EXE): $(OBJ)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@ $(OBJ_DIR)/sqlite3.o

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CXX) $(CPPFLAGS) -c $< $(CFLAGS) -o $@

install:
	sudo apt install sqlite3
	sudo apt install libsqlite3-dev
	sudo apt install unzip
	wget https://www.sqlite.org/2020/sqlite-amalgamation-3340000.zip \
		&& unzip sqlite-amalgamation-3340000.zip -d temp \
		&& cp temp/sqlite-amalgamation-3340000/sqlite3.h ./include \
		&& cp temp/sqlite-amalgamation-3340000/sqlite3.c ./src

	$(RM) -r temp
	$(RM) sqlite-amalgamation-3340000.zip

clean:
	$(RM) $(OBJ_DIR)/* $(EXE)

sqlite.o: src/sqlite3.c
	$(CC) $(SQLFLAGS) $(CFLAGS) -c $< && mv *.o bin