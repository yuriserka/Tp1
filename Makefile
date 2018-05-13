CC = g++
CFLAGS = -g -Wall -pedantic -std=c++11
TARGET = main
LIBS = 
SRCS = controladores.cc entidades.cc dominios.cc main.cc stubs.cc comandos.cc teste-dominios.cc
teste-entidades.cc
OBJS = $(SRCS:.c = .o)
MAIN = exec

all:	$(MAIN)

$(MAIN):$(OBJS)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

# Compilar no windows :
	# <build objects>
# g++ -g -Wall -pedantic -std=c++11 -c controladores.cc entidades.cc dominios.cc main.cc stubs.cc comandos.cc teste-dominios.cc teste-entidades.cc
	# <link objects>
# g++ -g -Wall -pedantic -std=c++11 -o main controladores.o entidades.o dominios.o main.o stubs.o comandos.o teste-dominios.o teste-entidades.o
	# <run>
# main.exe	