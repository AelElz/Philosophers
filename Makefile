RESET       = "\033[0m"
RED         = "\033[31m"
GREEN       = "\033[32m"
YELLOW      = "\033[33m"

NAME        = philo
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf
LINKER      = -lpthread

INCLUDES_DIR = includes
SRCS_DIR     = srcs

INCLUDES     = $(INCLUDES_DIR)/philo.h

SRC_FILES = \
	$(SRCS_DIR)/main.c \
	$(SRCS_DIR)/init.c \
	$(SRCS_DIR)/utils.c \
	$(SRCS_DIR)/str_utils.c \
	$(SRCS_DIR)/simulation.c

OBJ_FILES = \
	main.o \
	init.o \
	utils.o \
	str_utils.o \
	simulation.o

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo $(GREEN) " - Compiling $(NAME)..." $(RESET)
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LINKER) -o $(NAME)
	@echo $(YELLOW) " - Compiling FINISHED" $(RESET)

%.o: $(SRCS_DIR)/%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

clean:
	@$(RM) *.o
	@echo $(RED) " - Cleaned!" $(RESET)

fclean: clean
	@$(RM) $(NAME)
	@echo $(RED) " - Full Cleaned!" $(RESET)

re: fclean all

.PHONY: all clean fclean re
