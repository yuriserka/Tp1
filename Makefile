CC = g++
CFLAGS = -g -Wall -pedantic -std=c++11
TARGet = main
LIBS = 
SRCS = apresentacao.cc entidades.cc dominios.cc servicos.cc main.cc
OBJS = $(SRCS:.c = .o)
MAIN = exec

all:	$(MAIN)

$(MAIN):$(OBJS)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)
