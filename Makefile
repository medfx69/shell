# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 17:01:37 by mboukhal          #+#    #+#              #
#    Updated: 2022/05/24 18:15:08 by mboukhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.DEFAULT_GOAL		= all
NAME				= minishell
CFILES				= main.c

CFLAGS				= -Wall -Wextra -Werror
FSANI				= -g -fsanitize=address ; echo "\t$(GREEN)fsanitize active$(NC)"
INCLUDE				=  -lreadline

OBJS				= $(CFILES:.c=.o)

#################################################
#	echo info
#################################################
RED 				=\033[0;31m # Red
GREEN 				=\033[0;32m # Green
NC					=\033[0m\n$(S) # No Color
S					=----------------------------------
ECHO_CLEAN			=echo "$(OBJS)" | tr '\n' '\0' | tr ' ' '\n';\
					echo "\t\t\t$(RED)CLEAN!$(NC)"

ECHO_ALL			=echo "$(OBJS)" | tr '\n' '\0' | tr ' ' '\n';\
					 echo " \t\t\t$(GREEN)Created!$(NC)"| tr '-' '.';\
					 echo "$(NAME) \t\t$(GREEN)COMPILED!$(NC)"

ECHO_FCLEAN			=echo "\n$(NAME)"; $(ECHO_CLEAN);\
					 echo "$(NAME)   \t\t$(RED)FCLEAN!$(NC)"
#################################################


clean:
	@ $(RM) -rf $(OBJS)
	@ $(ECHO_CLEAN)
	
fclean:
	@ $(RM) -rf $(OBJS); $(RM) -rf $(NAME)
	@ $(ECHO_FCLEAN)

re: fclean all

.c.o:
	@ $(CC) $(CFLAGS) -c $< 

$(NAME): $(OBJS)
	@ $(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS) ######## $(FSANI)
	@ $(ECHO_ALL)
	
all: $(NAME) clean

.PHONY: re fclean all clean
