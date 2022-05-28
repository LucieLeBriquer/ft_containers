CC			= clang++ -std=c++98 #-Wall -Wextra -Werror 
RM			= rm -rf

NAME_SHORT	= containers
NAME		= ./$(NAME_SHORT)
NAME_STL	= $(NAME)STL

TEST		= .$(NAME_SHORT).res
TEST_STL	= .$(NAME_SHORT)STL.res

INCS_DIR	= ./includes/
MAIN_INC	= -I$(INCS_DIR)
INCS		= $(shell find $(INCS_DIR) -type f -name "*.hpp")

MAIN_SRC	= main.cpp

SRCS_DIR 	= ./sources/
SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.cpp" -not -name $(MAIN_SRC))
MAIN		= $(SRCS_DIR)$(MAIN_SRC)

OBJS_DIR	= ./objects/
OBJS		= $(SRCS:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)

_COLOR		= \033[32m
_BOLDCOLOR	= \033[32;1m
_RESET		= \033[0m
_CLEAR		= \033[0K\r\c
_OK			= [\033[32mOK\033[0m]
_OKSED		= [\\033[32mOK\\033[0m]

$(OBJS_DIR)%.o	: $(SRCS_DIR)%.cpp
			@mkdir -p $(OBJS_DIR)
			@echo "[..] $(NAME_SHORT)... compiling $*.cpp\r\c"
			@$(CC) $(MAIN_INC) -c $< -o $@
			@echo "$(_CLEAR)"

all			: $(NAME) $(NAME_STL)

$(NAME)		: $(OBJS) $(INCS) $(MAIN)
			@$(CC) $(OBJS) $(MAIN_INC) $(MAIN) -o $(NAME)
			@echo "$(_OK) $(NAME_SHORT) compiled"

$(NAME_STL)	: $(OBJS) $(INCS) $(MAIN)
			@$(CC) -DUSESTL $(OBJS) $(MAIN_INC) $(MAIN) -o $(NAME_STL)
			@echo "$(_OK) $(NAME_SHORT)STL compiled"

clean		:
ifeq ($(OBJS_DIR), ./)
			@$(RM) $(OBJS)
else
			@$(RM) $(OBJS_DIR)
endif

fclean		: clean
			@$(RM) $(NAME) $(NAME_STL)

re			: fclean all

diff		: $(NAME) $(NAME_STL)
			@$(NAME) 2>&1 | sed "s/ft:://g" > $(TEST)
			@$(NAME_STL) > $(TEST_STL) 2>&1
			@echo -n "output differences between vector and ft::vector "
			@diff -s $(TEST) $(TEST_STL) | grep "are identical" | wc -l | sed "s/1/[OK]/g" | sed "s/0/[KO]/g"
			@diff $(TEST) $(TEST_STL)
			@rm $(TEST) $(TEST_STL)
			

.PHONY		: all clean fclean re diff
