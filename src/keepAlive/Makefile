CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lmodbus

SRCS = keepAlive.c
OBJS = $(SRCS:.c=.o)
EXEC = keepAlive

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

OBJS: SRCS
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

