##
## EPITECH PROJECT, 2018
## MAKEFILE
## File description:
## compile makefile
##

SRC	=	read_file.c\
check.c\
djikstra.c\
list_management.c\
modify_path.c\
add.c\
fonctions.c\
check_two.c\
solver.c\
move_ants.c\
move_ants_bis.c\
error.c\
utility.c\
my_atoi.c\
parsing.c\
str_to_wordtab.c

OBJ	=	$(SRC:.c=.o)

NAME	=	test

all:	$(NAME) clean

$(NAME):	$(OBJ)
	ar rc libmy.a $(OBJ)

clean :
	rm -f $(OBJ)
