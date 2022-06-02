# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 17:01:37 by mboukhal          #+#    #+#              #
#    Updated: 2022/06/01 16:45:40 by mboukhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL		= all
NAME				= minishell
CFILES				= main.c ft_start.c execution/cd/ft_cd.c execution/ft_exec.c	\
					 parsing/main_pars.c test.c

CFLAGS				= -Wall -Wextra -Werror
FSANI				= -g -fsanitize=address ; echo "\t$(GREEN)fsanitize active$(NC)"
INCLUDE				=  -lreadline utils/ulib.a #-std=gnu11 

OBJS				= $(CFILES:.c=.o)

PRINT 				= 1

##############################################################################
#									 Style
##############################################################################
RED 				=\033[0;31m # Red
PURPLE 				=\033[0;35m # Purple
GREEN 				=\033[0;32m # Green
YELLOW 				=\033[0;33m # Yellow
CYAN				=\033[0;36m # Cyan
NCL					=$(S)\033[0m\n # No Color
NC					=\033[0m # No Color
S					=\n ----------------------------------
ECHO_CLEAN			=echo "$(CYAN)$(OBJS)$(NC)" | tr '\n' '\0' | tr ' ' '\n';\
					echo "\t\t$(RED)CLEAN!$(NCL)"

ECHO_ALL			=echo "$(CYAN)$(OBJS)$(NC)" | tr '\n' '\0' | tr ' ' '\n';\
					 echo "\t\t\t$(GREEN)Created!$(NCL)"| tr '-' '.';\
					 echo "$(CYAN)$(NAME)$(NC)\t\t$(GREEN)COMPILED!$(NCL)"

ECHO_FCLEAN			=echo "$(CYAN)$(NAME)$(NC)"; $(ECHO_CLEAN);\
					 echo "$(CYAN)$(NAME)$(NC)\t\t$(RED)FCLEAN!$(NCL)"
###############################################################################| tr '\n' ' ' | tr ' ' '\n';\

clean:
	@ make clean PRINT=$(PRINT) -C utils
ifeq ($(PRINT), 1)
	@ echo "$(PURPLE) ####### $(NAME) CLEAN ####### $(NCL)"
	@ $(ECHO_CLEAN)
endif
	@ $(RM) -rf $(OBJS)

fclean:
	@ make fclean PRINT=$(PRINT) -C utils
ifeq ($(PRINT), 1)
	@ echo "$(PURPLE) ###### $(NAME) FCLEAN ###### $(NCL)"
	@ $(ECHO_FCLEAN)
endif
	@ $(RM) -rf $(OBJS); $(RM) -rf $(NAME)

re: fclean all

.c.o:
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ make PRINT=$(PRINT) -C utils
	@ $(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS) #$(FSANI)
ifeq ($(PRINT), 1)
	@ echo "$(PURPLE) ####### $(NAME) START ####### $(NCL)"
	@ $(ECHO_ALL)
	@ echo "$(PURPLE) ######## $(NAME) END ######## $(NCL)"
endif
	
all: $(NAME) clean

.PHONY: re fclean all clean
