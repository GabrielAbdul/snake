CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I/usr/include/SDL2/
LIBS = -lSDL2
SRCS = snake.c
OBJS = $(SRCS:.c=.o)
MAIN = snake

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS)
.c.o:
	$(CC) $(CFLAGS) $(INDLUDES) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)
