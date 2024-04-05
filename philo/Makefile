NAME = philo

CC = cc
FLAGS = -Wall -Wextra -Werror -Ofast

LIBS = -pthread

SRC_DIR = src/
SRC_FILES =  $(addprefix $(SRC_DIR), main.c)

OBJ_DIR = obj/
OBJ_FILES = $(addprefix $(OBJ_DIR), $(notdir $(SRC_FILES:.c=.o)))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "Compiling executable..."
	@$(CC) $(FLAGS) $(SRC_FILES) -o $(NAME) $(LIBS)
	@echo "Done"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@) 
	@echo "Compiling objects..."
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "Done."

clean:
	@echo "Deleting object files and directory..."
	@rm -rf $(OBJ_DIR)
	@echo "Done."

fclean: clean
	@echo "Deleting executable..."
	@rm -f philo
	@echo "Done."

re: fclean all

.PHONY: all clean fclean re
