##
## EPITECH PROJECT, 2018
## MAKEFILE
## File description:
## makefile task03
##

SRC	=	main.c

OBJ	:=	$(SRC:.c=.o)

NAME	=	lemin

CPPFLAGS	=	-Iinclude

all:    $(NAME) clean

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	gcc -g -o $(NAME) $(SRC) -L./lib/my -lmy

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re:	fclean all
