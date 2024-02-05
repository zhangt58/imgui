.PHONY: clean

PLATFORM := Linux
ARCH := linux-x86_64
CC := gcc
ifeq ($(shell uname -s),Darwin)
	PLATFORM := Darwin
	ARCH := darwin-aarch64
	CC := clang
endif
TOP := $(shell realpath .)
CFLAGS := -I$(TOP)/include
CFLAGS += -I$(TOP)/include/os/$(PLATFORM)
CFLAGS += -I$(TOP)/include/compiler/$(CC)
LDFLAGS := -lca -lCom -L$(TOP)/lib/$(ARCH) -Wl,-rpath $(TOP)/lib/$(ARCH)

main:
	$(CC) -c ca.c -o ca.o $(CFLAGS)
	$(CC) -c main.c -o main.o $(CFLAGS)
	$(CC) main.o ca.o $(LDFLAGS) -o main

libcadata.so: ca.c ca.h
	$(CC) -c -fPIC ca.c -o ca.o $(CFLAGS)
	$(CC) -shared ca.o -o $@ $(LDFLAGS)
	

clean:
	/bin/rm *.o libcadata.so
