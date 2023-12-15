# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#              #
#    Updated: 2023/12/13 10:34:29 by gwenolalero      ###   ########.fr        #
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
TEST1_ARGS = "8 9 * 9 - 9 - 9 - 4 - 1 +"
TEST2_ARGS = "7 7 * 7 -"
TEST3_ARGS = "1 2 * 2 / 2 * 2 4 - +"
TEST4_ARGS = "(1 + 1)"
TEST5_ARGS = "4 9 - f - 4"
TEST6_ARGS = "7 7 7 -"
TEST7_ARGS = "3 -"
TEST8_ARGS = "7 0 /"
TEST9_ARGS = "6 9 -5 +"
TEST10_ARGS = "6 9 5 + - 7 8 + *"
TEST11_ARGS = "1 2 + 3 /"
TEST12_ARGS = "3 4 +"
TEST13_ARGS = "6 9 5 + *"
TEST14_ARGS = "3 4 + 5 *"
TEST15_ARGS = "9 2 / 3 +"
TEST16_ARGS = "5 2 * 8 /"
TEST17_ARGS = "3 2 *"
TEST18_ARGS = "2 3 * 4 + 5 6 * *"
TEST19_ARGS = "7"
TEST20_ARGS = ""

#------------------------------------------------------------------------------#
#                                   TOOLS                                      #
#------------------------------------------------------------------------------#

define HELP
-----------------------------------------------------------------------
$YTools available :$W
make fclean		$Y->$W Suppress executable and achives
make help		$Y->$W Display tools available
make pdf 		$Y->$W Open PDF subject
make re			$Y->$W Remove objects and executables and then remake
make rpn		$Y->$W Open a RPN calculator
make test		$Y->$W Run tests
-----------------------------------------------------------------------
endef
export HELP

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Executable name
NAME		=	RPN

# Compiler and flags
CC			=	c++
CPPFLAGS	=	-std=c++98 -Wall -Wextra -Werror
#CPPFLAGS	=	-std=c++98 -Wall -Wextra -Werror -g -fsanitize=address

# Remove
RM			=	rm -rf

# Files names
SRCS		=	$(wildcard *.cpp)
HEADS		=	$(wildcard *.hpp)

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
	@echo "\n$W------------------------ $(NAME) $Gcreated ✅ $W------------------------\n"

# Create all files .o (object) from files .cpp (source code)
$(OBJS_DIR)%.o: %.cpp $(HEADS)
	@$(CC) $(CFLAGS) -c $< -o $@

# Remove objects and executables
clean:
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YCLEANING $W<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
	@$(RM) $(OBJS_DIR)
	@echo "$W------------------- $(NAME) : $(OBJS_DIR) was $Rdeleted ❌$W-----------------"

fclean: clean
	@$(RM) $(NAME)
	@echo "\n$W--------- All exec. and archives successfully $Rdeleted ❌$W--------\n"
	@echo "$W>>>>>>>>>>>>>>>>>>>>> $YCleaning $Wis $Gdone ✅ $W<<<<<<<<<<<<<<<<<<<<<<\n"

# Display tools available
help:
	@echo "$$HELP"

# Open the subject
pdf:
	@open https://cdn.intra.42.fr/pdf/pdf/104442/en.subject.pdf#page=9

# Remove objects and executables and remake
re: fclean
	@$(MAKE) all

# Open a RPN calculator
rpn:
	@open https://rpn.startkoden.com

# For testing purposes
test:
	@echo "\n\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YTESTING $W<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
	@echo "\n$W------------------------ $CSubject tests $W-------------------------\n"
	@echo "$W----------------- $Z./RNP "\"8 9 x 9 - 9 - 9 - 4 - 1 +\"" $W------------"
	@./$(NAME) $(TEST1_ARGS)
	@echo "$W----------------- $Z./RNP "\"7 7 x 7 -\"" $W----------------------------"
	@./$(NAME) $(TEST2_ARGS)
	@echo "$W----------------- $Z./RNP "\"1 2 x 2 / 2 x 2 4 - +\"" $W----------------"
	@./$(NAME) $(TEST3_ARGS)
	@echo "$W----------------- $Z./RNP "\"\(1 + 1\)\"" $W------------------------------"
	@./$(NAME) $(TEST4_ARGS)
	@echo "\n\n$W--------------------- $CError handling tests $W---------------------\n"
	@echo "$RForbidden character$W"
	@echo "$W----------------- $Z./RNP "\"4 9 - f - 4\"" $W--------------------------"
	@./$(NAME) $(TEST5_ARGS)
	@echo "\n$RRemaining$W"
	@echo "$W----------------- $Z./RNP "\"7 7 7 -\"" $W------------------------------"
	@./$(NAME) $(TEST6_ARGS)
	@echo "\n$RNot enough operand$W"
	@echo "$W----------------- $Z./RNP "\"3 -\"" $W----------------------------------"
	@./$(NAME) $(TEST7_ARGS)
	@echo "\n$RDivision by 0$W"
	@echo "$W----------------- $Z./RNP "\"7 0 /\"" $W--------------------------------"
	@./$(NAME) $(TEST8_ARGS)
	@echo "\n$RInvalid syntax$W"
	@echo "$W----------------- $Z./RNP "\"6 9 -5 +\"" $W-----------------------------"
	@./$(NAME) $(TEST9_ARGS)
	@echo "\n$RNo input$W"
	@echo "$W----------------- $Z./RNP "\"\"" $W-------------------------------------"
	@./$(NAME) $(TEST20_ARGS)
	@echo "\n\n$W------------------------- $CValid tests $W--------------------------\n"
	@echo "$W----------------- $Z./RNP "\"6 9 5 + - 7 8 + x\"" $W--------------------"
	@./$(NAME) $(TEST10_ARGS)
	@echo "$W----------------- $Z./RNP "\"1 2 + 3 /\"" $W----------------------------"
	@./$(NAME) $(TEST11_ARGS)
	@echo "$W----------------- $Z./RNP "\"3 4 +\"" $W--------------------------------"
	@./$(NAME) $(TEST12_ARGS)
	@echo "$W----------------- $Z./RNP "\"6 9 5 + x\"" $W----------------------------"
	@./$(NAME) $(TEST13_ARGS)
	@echo "$W----------------- $Z./RNP "\"3 4 + 5 x\"" $W----------------------------"
	@./$(NAME) $(TEST14_ARGS)
	@echo "$W----------------- $Z./RNP "\"9 2 / 3 +\"" $W----------------------------"
	@./$(NAME) $(TEST15_ARGS)
	@echo "$W----------------- $Z./RNP "\"5 2 x 8 /\"" $W----------------------------"
	@./$(NAME) $(TEST16_ARGS)
	@echo "$W----------------- $Z./RNP "\"3 2 x\"" $W--------------------------------"
	@./$(NAME) $(TEST17_ARGS)
	@echo "$W----------------- $Z./RNP "\"2 3 x 4 + 5 6 x x\"" $W--------------------"
	@./$(NAME) $(TEST18_ARGS)
	@echo "$W----------------- $Z./RNP "\"7\"" $W------------------------------------"
	@./$(NAME) $(TEST19_ARGS)
	@echo "\n\n$W>>>>>>>>>>>>>>>>>>>>>>>>> $YEND TESTS ✅ $W<<<<<<<<<<<<<<<<<<<<<<<<<\n"

# Avoids file-target name conflicts
.PHONY: all clean fclean help pdf re rpn test

