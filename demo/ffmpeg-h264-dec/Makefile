SRCS := $(shell find . -name "*.c" -not -name "*_template.c")

CFLAGS := -I./ffmpeg-src -O2 -w -std=c99 -Wno-implicit-function-declaration
LDFLAGS := -lm

OBJS := $(SRCS:%.c=%.o)

h264dec: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f h264dec h264dec.* $(OBJS)
