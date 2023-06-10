CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lmodbus

SRCS = src/main.c
OBJS = $(SRCS:.c=.o)
EXEC = toem_HANMATEK_HM310T_api

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

OBJS: SRCS
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

