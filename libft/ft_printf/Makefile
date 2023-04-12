# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 08:56:56 by hkunnam-          #+#    #+#              #
#    Updated: 2023/01/21 08:56:56 by hkunnam-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
CC	=	gcc
CFLAGS =	-Wall -Wextra -Werror

#COLOURS

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC	= 	./src/ft_printf.c \
		./src/ft_nbrlen_base.c \
		./src/ft_putchar.c \
		./src/ft_putptr.c \
		./src/ft_putstr.c \
		./src/ft_strchr.c \
		./src/ft_strlen.c \
		./src/ft_unbrlen_base.c \
		./src/ft_unbrlen_base.c \
		./src/ft_uputnbr_base.c \
		./src/ft_putnbr_fd.c \

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		ar -rcs $(NAME) $(OBJ)
		@echo "$(GREEN)ft_printf compilation complete $(DEF_COLOR)"
		
clean:
		rm -rf $(OBJ)

fclean:	clean
		rm -rf $(NAME)

re:		clean all

.PHONY:	clean fclean re 