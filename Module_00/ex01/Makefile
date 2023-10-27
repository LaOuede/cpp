# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#              #
#    Updated: 2023/10/06 18:05:59 by gwenolalero      ###   ########.fr        #
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
make eval		$Y->$W Fill the phonebook with 8 contacts
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
NAME		=	phonebook

# Compiler and flags
CC			=	c++
CPPFLAGS	=	-std=c++98 -Wall -Wextra -Werror

# Remove
RM			=	rm -rf

# Files names
SRCS		=	$(wildcard *.cpp)
HEADS		=	$(wildcard *.hpp)


#------------------------------------------------------------------------------#
#                                  RULES                                       #
#------------------------------------------------------------------------------#

# Executable creation
all : $(NAME)

# Compilation
$(NAME) : $(SRCS) $(HEADS) Makefile
	@echo "\n--------------------- 🟢 $GCompiling$W ------------------------"
	@$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)
	@echo "\n$W------------------ $(NAME) $Gcreated ✅ $W-------------------\n"

# Remove objects and executables
clean:
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YCLEANING $W<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
	@$(RM) $(OBJS_DIR)
	@echo "$W------------------ $(NAME) : $(OBJS_DIR) was $Rdeleted ❌$W------------------"
	@$(RM) $(NAME)
	@echo "\n$W--------- All exec. and archives successfully $Rdeleted ❌$W--------\n"
	@echo "$W>>>>>>>>>>>>>>>>>>>>> $YCleaning $Wis $Gdone ✅ $W<<<<<<<<<<<<<<<<<<<<<<\n"

# Fill the phonebook with 8 contacts
eval: CPPFLAGS += -D EVAL=1
eval: clean all

# Display tools available
help:
	@echo "$$HELP"

# Open the subject
pdf:
	@open https://cdn.intra.42.fr/pdf/pdf/105040/fr.subject.pdf#page=7

# Remove objects and executables and remake
re: clean
	@$(MAKE) all

# Make and run the program
run : all
	@./$(NAME)

# Avoids file-target name conflicts
.PHONY: all clean eval help pdf re run