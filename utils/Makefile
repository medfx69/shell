.DEFAULT_GOAL	= all
NAME			= utilslib.a
CFLAGS			= -Wall -Wextra -Werror #	 -g3

FSANI			= -g -fsanitize=address ; echo "\t$(GREEN)fsanitize active$(NC)"


CFILES			= ft_split.c ft_strlen.c

PRINT			= 1

OBJS	= $(CFILES:.c=.o)

#################################################
#	echo info
#################################################
RED 				=\033[0;31m # Red
PURPLe 				=\033[0;35m # Purple
GREEN 				=\033[0;32m # Green
YELLOW 				=\033[0;33m # Yellow
NC					=\033[0m$(S) # No Color
S					=\n----------------------------------
ECHO_CLEAN			=echo "$(OBJS)" | tr '\n' '\0' | tr ' ' '\n';\
					echo "\n\t\t\t$(RED)CLEAN!$(NC)"

ECHO_ALL			=echo "$(OBJS)" | tr '\n' '\0' | tr ' ' '\n';\
					 echo "\n\t\t\t$(GREEN)Created!$(NC)"| tr '-' '.';\
					 echo "$(NAME)\n\t\t\t$(GREEN)COMPILED!$(NC)"

ECHO_FCLEAN			=echo "\n$(NAME)"; $(ECHO_CLEAN);\
					 echo "$(NAME)\n\t\t\t$(RED)FCLEAN!$(NC)"
#################################################

clean:
ifeq ($(PRINT), 1)
	@ echo "$(YELLOW)####### $(NAME) CLEAN ####### $(NC)"
	@ $(ECHO_CLEAN)
endif
	@ $(RM) -rf $(OBJS)
	
fclean:
ifeq ($(PRINT), 1)
	@ echo "$(YELLOW)###### $(NAME) FCLEAN ###### $(NC)"
	@ $(ECHO_FCLEAN)
endif
	@ $(RM) -rf $(OBJS); $(RM) -rf $(NAME)
	
re: fclean all

.c.o:
	@ $(CC) $(CFLAGS) -c $< 

$(NAME):$(OBJS)
	@ $(AR) rc $(NAME) $(OBJS) ######## $(FSANI)
ifeq ($(PRINT), 1)
	@ echo "$(YELLOW)####### $(NAME) START ####### $(NC)"
	@ $(ECHO_ALL)
	@ echo "$(YELLOW)######## $(NAME) END ######## $(NC)"
endif

all : $(NAME) 

.PHONY: re fclean all clean bonus
