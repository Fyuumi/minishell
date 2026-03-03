NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

PRINT       = printf
PRINTF_LIB  = $(PRINT)/ft_printf.a
PRINTF_MAKE = make -C $(PRINT)

all: $(PRINTF_LIB) $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(PRINTF_LIB) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(PRINTF_LIB) -o $(NAME_CLIENT)

$(PRINTF_LIB):
	$(PRINTF_MAKE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	$(PRINTF_MAKE) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	$(PRINTF_MAKE) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re