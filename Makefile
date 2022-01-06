SHELL=bash
NAME=philo
B_NAME=philo_bonus

CC=clang
CFLAGS=-Wall -Werror -Wextra
LFLAGS=-lpthread


LIBD=lib
LFTD=$(LIBD)/libft42
LIBFT=$(LFTD)/libft.a

INCD=inc $(LFTD)/inc
B_INCD=inc_bonus $(LFTD)/inc

SRCD=src
B_SRCD=src_bonus

OBJD=.obj
B_OBJD=.obj_bonus

SRC=$(wildcard $(SRCD)/*.c)
B_SRC=$(wildcard $(B_SRCD)/*.c)

OBJ=$(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRC))
B_OBJ=$(patsubst $(B_SRCD)/%.c, $(B_OBJD)/%.o, $(B_SRC))

all: $(OBJD) $(LIBFT) $(NAME)

bonus: $(B_OBJD) $(LIBFT) $(B_NAME)

$(OBJD):
	mkdir $@

$(B_OBJD):
	mkdir $@

$(LIBFT):
	$(MAKE) -C$(LFTD)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@ $(LFLAGS)

$(B_NAME): $(B_OBJ)
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@ $(LFLAGS)

$(OBJD)/%.o: $(SRCD)/%.c
	$(CC) $(CFLAGS) $(foreach dir, $(INCD), -I$(dir)) -c $< -o $@

$(B_OBJD)/%.o: $(B_SRCD)/%.c
	$(CC) $(CFLAGS) $(foreach dir, $(B_INCD), -I$(dir)) -c $< -o $@

clean:
	$(MAKE) fclean -C$(LFTD)
	rm -rf $(OBJD) $(B_OBJD)

fclean: clean
	rm -f $(NAME) $(B_NAME)

re: fclean all

debug:
	echo $(B_NAME) : $(B_SRC)
