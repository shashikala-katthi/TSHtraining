CC = gcc  # C compiler
CFLAGS = -fPIC # C flags
LDFLAGS = -shared   # linking flags
RM = rm -f   # rm command
TARGET_LIB = libcalc.so  # target lib

SRCS = calc.c   # source files
OBJS = $(SRCS:.c=.o)


main:main.c libcalc.so
	$(CC) -o main  main.c -I. libcalc.so


$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(SRCS:.c):%.c
	$(CC) $(CFLAGS) -MM $< >$@

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS}  main
