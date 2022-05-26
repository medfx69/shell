# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 17:01:37 by mboukhal          #+#    #+#              #
#    Updated: 2022/05/25 20:02:38 by mboukhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.DEFAULT_GOAL		= all
NAME				= minishell
CFILES				= main.c exec.c start.c

CFLAGS				= -Wall -Wextra -Werror
FSANI				= -g -fsanitize=address ; echo "\t$(GREEN)fsanitize active$(NC)"
INCLUDE				=  -lreadline #-std=gnu11

OBJS				= $(CFILES:.c=.o)

PRINT 				= 1

#################################################
#	echo info
#################################################
RED 				=\033[0;31m # Red
PURPLE 				=\033[0;35m # Purple
GREEN 				=\033[0;32m # Green
YELLOW 				=\033[0;33m # Yellow
NC					=\033[0m\n$(S) # No Color
S					=----------------------------------
ECHO_CLEAN			=echo "$(OBJS)" | tr '\n' '\0' | tr ' ' '\n';\
					echo "\n\t\t\t$(RED)CLEAN!$(NC)"

ECHO_ALL			=echo "$(OBJS)" | tr '\n' '\0' | tr ' ' '\n';\
					 echo "\n\t\t\t$(GREEN)Created!$(NC)"| tr '-' '.';\
					 echo "$(NAME)\n\t\t\t$(GREEN)COMPILED!$(NC)"

ECHO_FCLEAN			=echo "\n$(NAME)"; $(ECHO_CLEAN);\
					 echo "$(NAME)\n\t\t\t$(RED)FCLEAN!$(NC)"
#################################################


clean:
	@ make clean PRINT=$(PRINT) -C utils
ifeq ($(PRINT), 1)
	@ echo "$(PURPLE)####### $(NAME) CLEAN ####### $(NC)"
	@ $(ECHO_CLEAN)
endif
	@ $(RM) -rf $(OBJS)

fclean:
	@ make fclean PRINT=$(PRINT) -C utils
ifeq ($(PRINT), 1)
	@ echo "$(PURPLE)###### $(NAME) FCLEAN ###### $(NC)"
	@ $(ECHO_FCLEAN)
endif
	@ $(RM) -rf $(OBJS); $(RM) -rf $(NAME)

re: fclean all

.c.o:
	@ $(CC) $(CFLAGS) -c $< 

$(NAME): $(OBJS)
	@ make PRINT=$(PRINT) -C utils
	@ $(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS) ######## $(FSANI)
ifeq ($(PRINT), 1)
	@ echo "$(PURPLE)####### $(NAME) START ####### $(NC)"
	@ $(ECHO_ALL)
	@ echo "$(PURPLE)######## $(NAME) END ######## $(NC)"
endif
	
all: $(NAME) 

.PHONY: re fclean all clean
