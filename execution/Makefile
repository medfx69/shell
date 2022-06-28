NAME=philo
CC=gcc
FLAGS=-Wall -Wextra -Werror
SRC = functions/cd.c functions/ft_pwd.c ft_exec.c main.c
all : $(NAME)
$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
fclean: clean
	rm -f $(NAME) $(NAMEB)
clean:
	rm -f *.o
re: fclean all
.PHONY: fclean clean re all libft