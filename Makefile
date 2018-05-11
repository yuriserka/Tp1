CC = g++
CFLAGS = -g -Wall -pedantic -std=c++11
TARGET = main
LIBS = 
SRCS = controladores.cc entidades.cc dominios.cc main.cc stubs.cc
OBJS = $(SRCS:.c = .o)
MAIN = exec

all:	$(MAIN)

$(MAIN):$(OBJS)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)
