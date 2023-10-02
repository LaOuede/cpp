#------------------------------------------------------------------------------#
#                          BANNER & COLOR SETTINGS                             #
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
	@echo "$W--------------- $(NAME) : $(OBJS_DIR) was $Rdeleted ❌$W---------------"
	@$(RM) $(NAME)
	@echo "\n$W--------- All exec. and archives successfully $Rdeleted ❌$W--------\n"
	@echo "$W>>>>>>>>>>>>>>>>>>>>> $YCleaning $Wis $Gdone ✅ $W<<<<<<<<<<<<<<<<<<<<<<\n"

# Display tools available
help:
	@echo "$$HELP"

# Open the subject
pdf:
	@open https://cdn.intra.42.fr/pdf/pdf/104444/en.subject.pdf

# Remove objects and executables and remake
re: clean
	@$(MAKE) all

# Make and run the program
run : all
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>>> TESTS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
	@echo "$YTest 1$W"
	./$(NAME) "shhhhh... I think the students are asleep..."
	@echo "$Y\nTest 2$W"
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	@echo "$Y\nTest 3$W"
	./$(NAME)
	@echo "$Y\nTest 4$W"
	./$(NAME) "WAKE UP!"
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>> $WTESTS done ✅$W<<<<<<<<<<<<<<<<<<<<<<<<<<\n"

# Avoids file-target name conflicts
.PHONY: all dir clean help pdf re run