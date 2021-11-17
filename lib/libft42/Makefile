SHELL=bash

NAME=libft.a

SRCD=$(wildcard src/*)
OBJD=$(patsubst src/%, .obj/%, $(SRCD))
INCD=inc

SRC=$(wildcard src/*/*.c)
OBJ=$(patsubst src/%.c, .obj/%.o, $(SRC))
INC=$(wildcard inc/*.h)

CC=clang
CFLAGS=-Wall -Werror -Wextra

all: $(OBJD) $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

.obj/%.o: src/%.c
	$(CC) $(CFLAGS) -I $(INCD) -c $< -o $@

$(OBJD):
	mkdir -p $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	$(CC) $(CFLAGS) -I $(INCD) test.c $(NAME) -o $@ -lcriterion
	./$@

.PHONY: all clean fclean re
