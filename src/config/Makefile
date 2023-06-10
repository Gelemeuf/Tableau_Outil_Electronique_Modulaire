CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lmodbus

SRCS = config.c
OBJS = $(SRCS:.c=.o)
EXEC = config

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

OBJS: SRCS
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

