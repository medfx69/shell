.DEFAULT_GOAL	= all
NAME			= ulib.a
CFLAGS			= -Wall -Wextra -Werror #	 -g3

FSANI			= -g -fsanitize=address ; echo "\t$(GREEN)fsanitize active$(NC)"


CFILES			= ft_split.c ft_strlen.c ft_strncmp.c ft_putstr_fd.c 	\
				 ft_putchar_fd.c ft_putendl_fd.c

PRINT			= 1

OBJS	= $(CFILES:.c=.o)

#################################################
#	echo info
#################################################
RED 				=\033[0;31m # Red
GREEN 				=\033[0;32m # Green
YELLOW 				=\033[0;33m # Yellow
BLUE				=\033[0;34m # Blue
PURPLe 				=\033[0;35m # Purple
CYAN				=\033[0;36m # Cyan
NCL					=\033[0m\n$(S) # No Color
NC					=\033[0m # No Color
S					=$(BLUE)----------------------------------$(NC)
ECHO_CLEAN			=echo "$(CYAN)$(OBJS)$(NC)" | tr '\n' '\0' | tr ' ' '\n';\
					echo "\n\t\t\t$(RED)CLEAN!$(NCL)"

ECHO_ALL			=echo "$(CYAN)$(OBJS)$(NC)" | tr '\n' '\0' | tr ' ' '\n';\
					 echo "\n\t\t\t$(GREEN)Created!$(NCL)"| tr '-' '.';\
					 echo "$(CYAN)$(NAME)$(NC)\n\t\t\t$(GREEN)COMPILED!$(NCL)"

ECHO_FCLEAN			=echo "\n$(CYAN)$(NAME)$(NC)"; $(ECHO_CLEAN);\
					 echo "$(CYAN)$(NAME)$(NC)\n\t\t\t$(RED)FCLEAN!$(NCL)"
#################################################

clean:
ifeq ($(PRINT), 1)
	@ echo "$(YELLOW) ####### $(NAME) CLEAN ####### $(NCL)"
	@ $(ECHO_CLEAN)
endif
	@ $(RM) -rf $(OBJS)
	
fclean:
ifeq ($(PRINT), 1)
	@ echo "$(YELLOW) ###### $(NAME) FCLEAN ###### $(NCL)"
	@ $(ECHO_FCLEAN)
endif
	@ $(RM) -rf $(OBJS); $(RM) -rf $(NAME)
	
re: fclean all

.c.o:
	@ $(CC) $(CFLAGS) -c $< 

$(NAME):$(OBJS)
	@ $(AR) rc $(NAME) $(OBJS) ######## $(FSANI)
ifeq ($(PRINT), 1)
	@ echo "$(YELLOW) ######### $(NAME) START ######## $(NCL)"
	@ $(ECHO_ALL)
	@ echo "$(YELLOW) ######### $(NAME) END ########## $(NCL)"
endif

all : $(NAME) 

.PHONY: re fclean all clean bonus
