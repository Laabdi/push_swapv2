NAME = push_swap
NAME_BONUS = checker

# Main source files
SRC = main.c \
	check_input.c \
	push_swap_utils.c \
	initializing.c \
	stack.c \
	swap.c \
	push.c \
	rotate.c \
	reverse_rotate.c \
	sort_tiny.c \
	sort.c \
	get_position.c \
	calculate_cost.c \
	do_move.c \
	spliting_utils.c \
	ft_error_handler.c \
	push_swap.c \
	helpers.c

# Bonus source files
BONUS_SRC = reading.c \
	while.c \
	checker.c \
	actions.c \
	get_next_line_utils.c \
	get_next_line.c \
	check_input.c \
	push_swap_utils.c \
	initializing.c \
	stack.c \
	swap.c \
	push.c \
	rotate.c \
	reverse_rotate.c \
	sort_tiny.c \
	sort.c \
	get_position.c \
	calculate_cost.c \
	do_move.c \
	spliting_utils.c \
	ft_error_handler.c \
	push_swap.c \
	helpers.c

# Updated paths for header and source files
HEADER_PATH = includes/
SRC_PATH = src/
BONUS_PATH = bonus/
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ_PATH = obj/

# Generate object file names from source file names
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_PATH), $(BONUS_SRC:.c=.o))

# Main target for push_swap
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Mandatory Part: Compilation done."

# Bonus target for checker
$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Bonus Part: Compilation done."

# Rule to compile source files into object files
$(OBJ_PATH)%.o: $(SRC_PATH)%.c | directories
	$(CC) $(CFLAGS) -I$(HEADER_PATH) -c $< -o $@

# Rule to compile bonus source files into object files
$(OBJ_PATH)%.o: $(BONUS_PATH)%.c | directories
	$(CC) $(CFLAGS) -I$(HEADER_PATH) -c $< -o $@

# Ensure 'all' depends on 'directories' and 'push_swap'
all: directories $(NAME)

# Ensure 'bonus' depends on 'directories' and 'checker'
bonus: directories $(NAME_BONUS)

# Create obj directory
directories:
	mkdir -p $(OBJ_PATH)

# Cleaning rules
clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re directories bonus
