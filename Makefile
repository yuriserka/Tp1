CC = g++
CFLAGS = -g -Wall -pedantic -std=c++11
TARGET = main
LIBS = 
SRCS = controladores.cc entidades.cc dominios.cc main.cc servicos.cc sql.cc stubs.cc comandos.cc teste-dominios.cc teste-entidades.cc
OBJS = $(SRCS:.c = .o)
MAIN = exec

#sqlite:
#	gcc -DSQLITE_THREADSAFE=0 -DSQLITE_OMIT_LOAD_EXTENSION -c $(SQL_C)

all:	$(MAIN)

$(MAIN):$(OBJS)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

# Compilar no windows :
	# build objects
# g++ -g -Wall -pedantic -std=c++11 -c controladores.cc entidades.cc dominios.cc main.cc stubs.cc comandos.cc teste-dominios.cc teste-entidades.cc sql.cc servicos.cc
	# link objects
# g++ -g -Wall -pedantic -std=c++11 -o main controladores.o entidades.o dominios.o main.o stubs.o comandos.o teste-dominios.o teste-entidades.o sql.o sqlite3.o servicos.o
	# run
# main.exe	