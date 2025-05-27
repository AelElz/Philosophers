NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
PFLAGS = -pthread

SRC = main.c philo_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(PFLAGS) $(OBJ) -o $(NAME)
clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
