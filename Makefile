NAME = push_swap

CC = cc
CFLAGS = -g -Wall

SRC = main.c utils.c push_swap.c parse.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)/includes -I.

all: $(NAME)

$(NAME) : $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
