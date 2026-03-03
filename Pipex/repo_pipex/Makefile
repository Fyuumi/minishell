# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 17:07:05 by cdenaux           #+#    #+#              #
#    Updated: 2026/01/05 14:10:33 by cdenaux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

#Commande pour creer la bibliotheque
AR = ar rcs

#Commande pour supprimer les fichiers
RM = rm -f 

# Tous les fichiers sources (mandatory)
SRCS = 	children.c cmd_utils.c errors.c ft_printf.c ft_split.c ft_strjoin.c \
		main.c pipex.c \

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Fichier header
HEADER = pipex.h

# Regle par defaut
all: $(NAME)

# Creation de la bibliotheque
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compilation des fichiers objets
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	$(RM) $(OBJS)

# Nettoyage complet
fclean: clean
	$(RM) $(NAME)

# Recompilation complete
re: fclean all

# Declaration des regles qui ne sont pas des fichiers
.PHONY: all clean fclean re
