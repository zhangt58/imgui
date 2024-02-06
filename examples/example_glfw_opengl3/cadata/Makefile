.PHONY: clean cadata

PLATFORM := Linux
ARCH := linux-x86_64
CC := gcc
CADATA_LIBNAME := libcadata.so
CFLAGS := -I$(TOP)/include
ifeq ($(shell uname -s),Darwin)
	PLATFORM := Darwin
	ARCH := darwin-aarch64
	CC := clang
	CADATA_LIBNAME := libcadata.dylib
else ifeq ($(findstring MINGW64_NT,$(shell uname -s)),MINGW64_NT)
	PLATFORM := WIN32
	ARCH := windows-x64-mingw
	CADATA_LIBNAME := libcadata.dll
endif

TOP := $(shell realpath .)
CFLAGS := -I$(TOP)/include
CFLAGS += -I$(TOP)/include/os/$(PLATFORM)
CFLAGS += -I$(TOP)/include/compiler/$(CC)
LDFLAGS := -lca -lCom -L$(TOP)/lib/$(ARCH) -Wl,-rpath $(TOP)/lib/$(ARCH)

cadata: $(CADATA_LIBNAME)
main:
	$(CC) -c ca.c -o ca.o $(CFLAGS)
	$(CC) -c main.c -o main.o $(CFLAGS)
	$(CC) main.o ca.o $(LDFLAGS) -o main

$(CADATA_LIBNAME): ca.c ca.h
	$(CC) -c -fPIC ca.c -o ca.o $(CFLAGS)
	# $(CC) -c ca.c -o ca.o $(CFLAGS)
	$(CC) -shared ca.o -o $@ $(LDFLAGS)
	
fix:
	#mv /c/msys64/mingw64/include/time.h /c/msys64/mingw64/include/time.h.bak
	#mv /c/msys64/mingw64/include/sys/timeb.h /c/msys64/mingw64/include/sys/timeb.h.bak
	cp /c/msys64/mingw64/include/time.h.bak /c/msys64/mingw64/include/time.h
	cp /c/msys64/mingw64/include/sys/timeb.h.bak /c/msys64/mingw64/include/sys/timeb.h
	

clean:
	/bin/rm *.o $(CADATA_LIBNAME)
