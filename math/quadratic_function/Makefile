CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

SRCS = main.c quadratic_function.c
OBJS = $(SRCS:.c=.o)
EXEC = start

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
