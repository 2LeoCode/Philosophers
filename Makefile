SHELL=bash

BUILD_DIR=build

NAME=philo
BONUS_NAME=philo_bonus

all: $(NAME)

$(NAME) $(BONUS_NAME): $(BUILD_DIR)
	$(MAKE) $@ --no-print-directory -C$(BUILD_DIR)

bonus: $(BONUS_NAME)

$(BUILD_DIR):
	cmake -B$(BUILD_DIR) -H.

clean:
	$(MAKE) clean -s --no-print-directory -C$(BUILD_DIR)

fclean:
	$(MAKE) fclean -s --no-print-directory -Clib/libft42
	rm -rf $(BUILD_DIR)

re: fclean all

.PHONY: all bonus clean fclean re
