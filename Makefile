NAME = ./solong
INCLUDE_DIRS := includes
INCLUDES := $(addprefix -I, $(INCLUDE_DIRS))
SRC = $(wildcard src/*.c)
OBJ := $(SRC:.c=.o)
RM = rm -f
MAKE = make

all: libft.a minilibx $(NAME) 

libft.a:
	make -C libs/libft/
	make bonus -C libs/libft/

minilibx:
	$(MAKE) -C libs/mlx/

%.o: %.c
	$(CC) -Ilibs/mlx -c $^ -o $@ $(INCLUDES)

$(NAME): $(OBJ)
	$(CC) $^ -Llibs/mlx/ -lmlx -framework OpenGL -framework AppKit -Llibs/libft/ -lft -o $@ $(INCLUDES)


clean:
	$(MAKE) clean -C ./libs/libft
	$(MAKE) -C libs/mlx/ clean
	$(RM)   $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./libs/libft
		$(RM)   $(NAME)

re: fclean  $(NAME)

bonus: $(NAME)

.PHONY:         all clean fclean bonus

#	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@