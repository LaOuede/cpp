# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#              #
#    Updated: 2023/12/13 08:13:55 by gwenolalero      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                   COLOR SETTINGS                             #
#------------------------------------------------------------------------------#

# Colors settings
W		:= \033[0m
R		:= \033[1;31m
G		:= \033[1;32m
Y		:= \033[1;33m
C 		:= \033[1;36m

#------------------------------------------------------------------------------#
#                                   TESTS                                      #
#------------------------------------------------------------------------------#

# For testing purposes only
TEST1_ARGS = `jot -r 10 1 100000 | tr '\n' ' '`
TEST2_ARGS = `awk 'BEGIN { srand(); while (length(arr) < 23) { num = int(rand() * 23) + 1; if (!(num in arr)) { arr[num]; print num } } }' /dev/null`
TEST3_ARGS = `awk 'BEGIN { srand(); while (length(arr) < 100) { num = int(rand() * 100) + 1; if (!(num in arr)) { arr[num]; print num } } }' /dev/null`
TEST4_ARGS = `awk 'BEGIN { srand(); while (length(arr) < 333) { num = int(rand() * 333) + 1; if (!(num in arr)) { arr[num]; print num } } }' /dev/null`
TEST5_ARGS = `awk 'BEGIN { srand(); while (length(arr) < 1000) { num = int(rand() * 1000) + 1; if (!(num in arr)) { arr[num]; print num } } }' /dev/null`
TEST6_ARGS = `awk 'BEGIN { srand(); while (length(arr) < 5555) { num = int(rand() * 5555) + 1; if (!(num in arr)) { arr[num]; print num } } }' /dev/null`
TEST7_ARGS = `awk 'BEGIN { srand(); while (length(arr) < 10000) { num = int(rand() * 10000) + 1; if (!(num in arr)) { arr[num]; print num } } }' /dev/null`
TEST8_ARGS = `awk 'BEGIN { srand(); while (length(arr) < 29999) { num = int(rand() * 29999) + 1; if (!(num in arr)) { arr[num]; print num } } }' /dev/null`

#------------------------------------------------------------------------------#
#                                   TOOLS                                      #
#------------------------------------------------------------------------------#

define HELP
-----------------------------------------------------------------------
$YTools available :$W
make debug		$Y->$W Run verbose program
make fclean		$Y->$W Suppress executable and achives
make help		$Y->$W Display tools available
make pdf		$Y->$W Open PDF subject
make re			$Y->$W Remove objects and executables and then remake
make test		$Y->$W Run tests
-----------------------------------------------------------------------
endef
export HELP

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Executable name
NAME		=	PmergeMe

# Compiler and flags
CC			=	c++
CPPFLAGS	=	-std=c++98 -Wall -Wextra -Werror
#CPPFLAGS	=	-std=c++98 -Wall -Wextra -Werror -g -fsanitize=address

# Remove
RM			=	rm -rf

# Files names
SRCS		=	$(wildcard *.cpp)
HEADS		=	$(wildcard *.hpp, *.tpp)

OBJS_DIR	=	./obj/
OBJS_LIST	=	$(patsubst %.cpp, %.o, $(SRCS))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

#------------------------------------------------------------------------------#
#                                  RULES                                       #
#------------------------------------------------------------------------------#

# Executable creation
all : dir $(NAME)

#Create directory for *.o files
dir:
	@mkdir -p $(OBJS_DIR)

# Compilation
$(NAME) : $(OBJS)
	@echo "$(ERASE_LINE)$W\n>>>>>>>>>>>>>>>>>>>> $YCompilation $Wis $Gdone ✅ $W<<<<<<<<<<<<<<<<<<<<"
	@$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)
	@echo "\n$W---------------------- $(NAME) $Gcreated ✅ $W---------------------\n"

# Create all files .o (object) from files .cpp (source code)
$(OBJS_DIR)%.o: %.cpp $(HEADS)
	@$(CC) $(CFLAGS) -c $< -o $@

# Remove objects and executables
clean:
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YCLEANING $W<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
	@$(RM) $(OBJS_DIR)
	@echo "$W---------------- $(NAME) : $(OBJS_DIR) was $Rdeleted ❌$W---------------"

# Run debug tests
debug: CPPFLAGS += -D DEBUG=1
debug: clean all

fclean: clean
	@$(RM) $(NAME)
	@echo "\n$W--------- All exec. and archives successfully $Rdeleted ❌$W--------\n"
	@echo "$W>>>>>>>>>>>>>>>>>>>>> $YCleaning $Wis $Gdone ✅ $W<<<<<<<<<<<<<<<<<<<<<<\n"

# Display tools available
help:
	@echo "$$HELP"

# Open the subject
pdf:
	@open https://cdn.intra.42.fr/pdf/pdf/104442/en.subject.pdf#page=11

# Remove objects and executables and remake
re: fclean
	@$(MAKE) all

# For testing purposes
test:
	@echo "\n\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YTESTING $W<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
	@echo "$W------------------- $Y./PmergeMe 10 elements $W---------------------"
	@./$(NAME) $(TEST1_ARGS)
	@echo "$W------------------- $Y./PmergeMe 23 elements $W---------------------"
	@./$(NAME) $(TEST2_ARGS)
	@echo "$W------------------- $Y./PmergeMe 100 elements $W--------------------"
	@./$(NAME) $(TEST3_ARGS)
	@echo "$W------------------- $Y./PmergeMe 333 elements $W--------------------"
	@./$(NAME) $(TEST4_ARGS)
	@echo "$W------------------ $Y./PmergeMe 1000 elements $W--------------------"
	@./$(NAME) $(TEST5_ARGS)
	@echo "$W------------------ $Y./PmergeMe 5555 elements $W--------------------"
	@./$(NAME) $(TEST6_ARGS)
	@echo "$W----------------- $Y./PmergeMe 10000 elements $W--------------------"
	@./$(NAME) $(TEST7_ARGS)
	@echo "$W----------------- $Y./PmergeMe 29999 elements $W--------------------"
	@./$(NAME) $(TEST8_ARGS)
	@echo "\n\n$W>>>>>>>>>>>>>>>>>>>>>>>>> $YEND TESTS ✅ $W<<<<<<<<<<<<<<<<<<<<<<<<<\n"

# Avoids file-target name conflicts
.PHONY: all clean debug fclean help pdf re rpn test

