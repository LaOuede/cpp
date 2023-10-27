# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#              #
#    Updated: 2023/10/09 10:56:35 by gle-roux         ###   ########.fr        #
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
#                                   TOOLS                                      #
#------------------------------------------------------------------------------#

define HELP
-----------------------------------------------------------------------
$YTools available :$W
make eval		$Y->$W ...
make help		$Y->$W Display tools available
make pdf 		$Y->$W Open PDF subject
make re			$Y->$W Remove objects and executables and then remake
make run		$Y->$W Make and run some tests
-----------------------------------------------------------------------
endef
export HELP


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Executable name
NAME		=	horde

# Compiler and flags
CC			=	c++
CPPFLAGS	=	-std=c++98 -Wall -Wextra -Werror

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
#$(NAME) : $(SRCS) $(HEADS) Makefile $(OBJS_LIST)
$(NAME) : $(OBJS)
	@echo "$(ERASE_LINE)$W\n>>>>>>>>>>>>>>>>>>> $YCompilation $Wis $Gdone ✅ $W<<<<<<<<<<<<<<<<<<<<"
	@$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)
	@echo "\n$W---------------------- $(NAME) $Gcreated ✅ $W-----------------------\n"

# Create all files .o (object) from files .cpp (source code)
$(OBJS_DIR)%.o: %.cpp $(HEADS)
	@$(CC) $(CFLAGS) -c $< -o $@

# Remove objects and executables
clean:
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YCLEANING $W<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
	@$(RM) $(OBJS_DIR)
	@echo "$W----------------- $(NAME) : $(OBJS_DIR) was $Rdeleted ❌$W-----------------"
	@$(RM) $(NAME)
	@echo "\n$W--------- All exec. and archives successfully $Rdeleted ❌$W--------\n"
	@echo "$W>>>>>>>>>>>>>>>>>>>>> $YCleaning $Wis $Gdone ✅ $W<<<<<<<<<<<<<<<<<<<<<<\n"

# Display tools available
help:
	@echo "$$HELP"

# Open the subject
pdf:
	@open https://cdn.intra.42.fr/pdf/pdf/66969/fr.subject.pdf#page=7

# Remove objects and executables and remake
re: clean
	@$(MAKE) all

# Make and run the program
test : all
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>>> TESTS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
	@echo "$YTest 1$W"
	./$(NAME) -1 Ed
	@echo "$Y\nTest 2$W"
	./$(NAME) Salut Frankenstein
	@echo "$Y\nTest 3$W"
	./$(NAME)
	@echo "$Y\nTest 4$W"
	./$(NAME) 7
	@echo "$Y\nTest 5$W"
	./$(NAME) 5 "Frankenstein Von Richten"
	@echo "$Y\nTest 6$W"
	./$(NAME) 1 Ed
	@echo "$Y\nTest 7$W"
	./$(NAME) 15 Frankenstein
	@echo "$Y\nTest 8$W"
	./$(NAME) 50 R2D2
	@echo "$Y\nTest 9$W"
	leaks --atExit -- ./$(NAME) 12 Dracula
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>> $WTESTS done ✅$W<<<<<<<<<<<<<<<<<<<<<<<<<<\n"

# Avoids file-target name conflicts
.PHONY: all clean help pdf re test