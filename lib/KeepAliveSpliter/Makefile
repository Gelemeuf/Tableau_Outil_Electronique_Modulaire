CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lmodbus

SRCS = src/main.c
OBJS = $(SRCS:.c=.o)
EXEC = KeepAliveSpliter

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

OBJS: SRCS
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

