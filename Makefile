##
## EPITECH PROJECT, 2022
## my_printf.c
## File description:
## makefile
##

CC	=	gcc

SRC	=	src/main.c	

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

RM	=	rm -f

all:	$(NAME)
	cd src

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
