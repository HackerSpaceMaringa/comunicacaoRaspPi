ARCH=$(shell uname -m)
CC=gcc
CCPP=g++
LIBBOOST=-lrt -lboost_system -lboost_thread -I/usr/include/ -lpthread
SRC= ./src
CFLAGS= -O0 -g -w
LDrepa= -pthread -lpthread $(SHAREDOBJ) -lpython2.7
DIRMANAGEMENT=$(SRC)/management/
HEADERS= -I$(SRC)/include/ -I/usr/include/mysql/ -I./repd/ -I$(DIRMANAGEMENT)include/

all: client

client:
	$(CCPP) $(SRC)/client2.c  $(DIRMANAGEMENT)Management.cpp -o client $(CFLAGS) $(LDrepa) $(HEADERS) $(LIBBOOST) -std=c++11

clear.o:
	rm -f *.o
	rm -f *.so

clear: clear.o
	rm -f client;\
