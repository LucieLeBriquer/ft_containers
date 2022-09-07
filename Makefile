CC			= clang++ -std=c++98 -Wall -Wextra -Werror 
RM			= rm -rf

NAME_SHORT	= containers
NAME		= ./$(NAME_SHORT)
NAME_STL	= $(NAME)STL

TEST		= .$(NAME_SHORT).res
TEST_STL	= .$(NAME_SHORT)STL.res

INCS_DIR	= ./includes/tests/
MAIN_INC	= -I$(INCS_DIR)
INCS		= $(addprefix $(INCS_DIR), \
				testMap.hpp \
				testStack.hpp \
				testUtils.hpp \
				testVector.hpp \
			)

MAIN_SRC	= main.cpp

SRCS_DIR 	= ./sources/
SRCS		= $(addprefix $(SRCS_DIR), \
					$(addprefix map/, \
						access.cpp \
						bound.cpp \
						construct.cpp \
						erase.cpp \
						find.cpp \
						insert.cpp \
						iterators.cpp \
						observers.cpp \
					) \
					$(addprefix vector/, \
						access.cpp \
						compare.cpp \
						construct.cpp \
						erase.cpp \
						insert.cpp \
						iterators.cpp \
					) \
					$(addprefix stack/, \
						compare.cpp \
						containers.cpp \
					) \
					$(addprefix utils/, \
						print.cpp \
					) \
			)
MAIN		= $(SRCS_DIR)$(MAIN_SRC)

OBJS_DIR	= ./objects/objectsFT/
OBJSSTL_DIR	= ./objects/objectsSTL/
OBJS		= $(SRCS:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)
OBJSSTL		= $(SRCS:$(SRCS_DIR)%.cpp=$(OBJSSTL_DIR)%.o)

SUB			= map vector stack utils

SUB_DIRS	= $(addprefix $(OBJS_DIR), $(SUB))
SUBSTL_DIRS	= $(addprefix $(OBJSSTL_DIR), $(SUB))

_COLOR		= \033[32m
_BOLDCOLOR	= \033[32;1m
_RESET		= \033[0m
_CLEAR		= \033[0K\r\c
_OK			= [\033[32mOK\033[0m]
_KO			= [\033[31mKO\033[0m]

$(OBJS_DIR)%.o	: $(SRCS_DIR)%.cpp
			@mkdir -p $(OBJS_DIR) $(SUB_DIRS)
			@echo "[..] $(NAME_SHORT)... compiling $*.cpp\r\c"
			@$(CC) $(MAIN_INC) -c $< -o $@
			@echo "$(_CLEAR)"


$(OBJSSTL_DIR)%.o	: $(SRCS_DIR)%.cpp
			@mkdir -p $(OBJSSTL_DIR) $(SUBSTL_DIRS)
			@echo "[..] $(NAME_SHORT)STL... compiling $*.cpp\r\c"
			@$(CC) -DUSESTL $(MAIN_INC) -c $< -o $@
			@echo "$(_CLEAR)"

all			: $(NAME) $(NAME_STL)

$(NAME)		: $(OBJS) $(INCS) $(MAIN)
			@$(CC) $(OBJS) $(MAIN_INC) $(MAIN) -o $(NAME)
			@echo "$(_OK) $(NAME_SHORT) compiled"

$(NAME_STL)	: $(OBJSSTL) $(INCS) $(MAIN)
			@$(CC) -DUSESTL $(OBJSSTL) $(MAIN_INC) $(MAIN) -o $(NAME_STL)
			@echo "$(_OK) $(NAME_SHORT)STL compiled"

clean		:
			@$(RM) "./objects"

fclean		: clean
			@$(RM) $(NAME) $(NAME_STL)

re			: fclean all

diff		: $(NAME) $(NAME_STL)
			@$(NAME) 2>&1 | sed "s/ft:://g" > $(TEST)
			@$(NAME_STL) > $(TEST_STL) 2>&1
			@diff $(TEST) $(TEST_STL) && echo -n "$(_OK) No o" || echo -n "$(_KO) O"
			@echo "utput differences"
			@rm $(TEST) $(TEST_STL)

TEST_INC_BASE	= ^include_path=.*$
TEST_INC_VECTOR = include_path=\"..\/includes\/vector\"
TEST_INC_MAP 	= include_path=\"..\/includes\/map\"
TEST_INC_STACK	= include_path=\"..\/includes\/stack\"

test		:
			@$(RM) "tester"
			@git clone git@github.com:mli42/containers_test.git tester
			@sed -i 's/$(TEST_INC_BASE)/$(TEST_INC_STACK)/' tester/fct.sh
			@cd tester; ./do.sh stack; echo ""
			@sed -i 's/$(TEST_INC_BASE)/$(TEST_INC_VECTOR)/' tester/fct.sh
			@cd tester; ./do.sh vector; echo ""
			@sed -i 's/$(TEST_INC_BASE)/$(TEST_INC_MAP)/' tester/fct.sh
			@cd tester; ./do.sh map; echo ""
			

.PHONY		: all clean fclean re diff test
