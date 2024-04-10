NAME = philo

CC = cc
FLAGS = -Wall -Wextra -Werror -Ofast
DEBUG_FLAGS = -Wall -Wextra -Werror -gdwarf-4

LIBS = -pthread

SRC_DIR = src/
SRC_FILES =  $(addprefix $(SRC_DIR), \
			 main.c \
			 routine.c \
			 utils.c \
			 utils2.c \
			 time.c \
			 input_validation.c \
			 simulation.c)

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

debug:
	@echo "Compiling debug version"
	@$(CC) $(DEBUG_FLAGS) $(SRC_FILES) -o $(NAME) $(LIBS)
	@echo "Done"

.PHONY: all clean fclean re debug
