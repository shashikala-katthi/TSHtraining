CROSS_COMPILE ?=
CC	:= $(CROSS_COMPILE)gcc
CFLAGS ?= -Iinclude/linux
LDFLAGS	?=

SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean: 
	-rm -f *.o
	-rm -f $(PROGS)
