CXX = g++
CC = gcc
CXXFLAGS = -g -Wall -pedantic -std=c++11
CFLAGS = -g -Wall -pedantic
SQLFLAGS = -DSQLITE_THREADSAFE=0 -DSQLITE_OMIT_LOAD_EXTENSION
TARGET = main
LIBS = 
SRCS = comandos.cc controladores.cc dominios.cc entidades.cc main.cc servicos.cc sql.cc comandos.cc teste-dominios.cc teste-entidades.cc
SQLSRC = sqlite3.c
SQLOBJ = sqlite3.o
OBJS = $(SRCS:.cxx = .o)
MAIN = exec

all:	$(MAIN)

sqlite:
	$(CC) $(SQLFLAGS) -c $(SQLSRC)

$(MAIN):$(OBJS)
		$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(SQLOBJ) $(LIBS)

.cxx.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)