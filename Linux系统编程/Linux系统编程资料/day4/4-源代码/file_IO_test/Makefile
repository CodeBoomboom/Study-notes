src = $(wildcard *.c)
obj = $(patsubst %.c, %, $(src))

all:$(obj)

CFLAGES=-Wall -g

$(obj):%:%.c
	gcc $< -o $@ $(CFLAGS)

clean:
	-rm -rf $(obj)

.PHONY:clean all
