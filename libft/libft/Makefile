# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 13:09:45 by hkunnam-          #+#    #+#              #
#    Updated: 2023/02/13 13:52:53 by hkunnam-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT #
NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= @rm -f

# SOURCES #
SRC	= ./src/check/ft_isalnum.c\
	  ./src/check/ft_isalpha.c\
	  ./src/check/ft_isascii.c\
	  ./src/check/ft_isdigit.c\
	  ./src/check/ft_isprint.c\
	  ./src/list/ft_lstadd_back.c\
	  ./src/list/ft_lstadd_front.c\
	  ./src/list/ft_lstclear.c\
	  ./src/list/ft_lstdelone.c\
	  ./src/list/ft_lstiter.c\
	  ./src/list/ft_lstlast.c\
	  ./src/list/ft_lstmap.c\
	  ./src/list/ft_lstnew.c\
	  ./src/list/ft_lstsize.c\
	  ./src/memory/ft_bzero.c\
	  ./src/memory/ft_calloc.c\
	  ./src/memory/ft_memchr.c\
	  ./src/memory/ft_memcmp.c\
	  ./src/memory/ft_memcpy.c\
	  ./src/memory/ft_memmove.c\
	  ./src/memory/ft_memset.c\
	  ./src/print/ft_putchar_fd.c\
	  ./src/print/ft_putendl_fd.c\
	  ./src/print/ft_putnbr_fd.c\
	  ./src/print/ft_putstr_fd.c\
	  ./src/string/ft_atoi.c\
	  ./src/string/ft_itoa.c\
	  ./src/string/ft_split.c\
	  ./src/string/ft_strchr.c\
	  ./src/string/ft_strdup.c\
	  ./src/string/ft_striteri.c\
	  ./src/string/ft_strjoin.c\
	  ./src/string/ft_strlcat.c\
	  ./src/string/ft_strlcpy.c\
	  ./src/string/ft_strlen.c\
	  ./src/string/ft_strmapi.c\
	  ./src/string/ft_strncmp.c\
	  ./src/string/ft_strnstr.c\
	  ./src/string/ft_strrchr.c\
	  ./src/string/ft_strtrim.c\
	  ./src/string/ft_substr.c\
	  ./src/string/ft_tolower.c\
	  ./src/string/ft_toupper.c\
	  ./src/gnl/get_next_line.c \
	  ./src/gnl/get_next_line_utils.c \
	  ./src/string/ft_atoi_base.c \
	  
OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SILENT:
	all
.PHONY: 
	all clean fclean re
