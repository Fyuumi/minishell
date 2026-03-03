# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 16:13:55 by opaulman          #+#    #+#              #
#    Updated: 2025/07/03 16:43:07 by opaulman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
      ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
      ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putstr_fd.c ft_split.c \
      ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
      ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
      ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	  ft_putnbr_fd.c ft_putendl_fd.c 
			

BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c
		
OBJ =	$(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

CC =	cc
CFLAGS =	-Wall -Wextra -Werror


all:	$(NAME)

$(NAME):	$(OBJ) $(BONUS_OBJ)
	ar rcs $@ $^


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)
clean:	
	rm -f $(OBJ) $(BONUS_OBJ)
fclean:	
	rm -f $(NAME) $(OBJ) $(BONUS_OBJ)
re:     	
	$(MAKE) fclean
	$(MAKE) all			

.PHONY: all clean fclean re bonus