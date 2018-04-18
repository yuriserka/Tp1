CC = g++
CFLAGS = -g -Wall -pedantic -std=c++11
TARGet = main
LIBS = 
SRCS = entidades.cc dominios.cc unit-test-dominios.cc unit-test-entidades.cc testes.cc main.cc
OBJS = $(SRCS:.c = .o)
MAIN = exec

all:	$(MAIN)

$(MAIN):$(OBJS)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)
