NAME=minishell
CC=gcc
FLAGS=-Wall -Wextra -Werror
SRC = functions/add_and_or_create_to_afile.c functions/cd.c  functions/export.c  functions/unset.c \
		functions/add_env_var.c functions/echo.c  functions/ft_pwd.c functions/mod_env.c functions/ft_splite.c \
		functions/ft_strjoin.c functions/ft_strdup.c functions/ft_substr.c  ft_exec.c main.c
all : $(NAME)
$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
fclean: clean
	rm -f $(NAME) $(NAMEB)
clean:
	rm -f *.o
re: fclean all
.PHONY: fclean clean re all libft