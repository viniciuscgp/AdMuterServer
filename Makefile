all: admuterserver

CC = gcc
SRCS = $(wildcard src/*.c)
HEADERS = $(wildcard include/*.h)
FLAGS= "-lws2_32"
admuterserver: $(SRCS) $(HEADERS)
	$(CC) $(SRCS) $(FLAGS) -o "$@"


clean: del *.exe
