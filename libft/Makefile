NAME =	libft.a

SRC = ft_atol.c ft_split.c\
		ft_printf.c ft_putstr.c ft_putchar.c ft_putnbr.c ft_unsig_putnbr.c ft_printhexa.c ft_pointer.c

OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all