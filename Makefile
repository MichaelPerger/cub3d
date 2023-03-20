NAME		= cub3d
	
CC			= cc
FLAGS		= -Wall -Wextra -Werror -g
RM			= rm -rf
ALL_LIBS	= -L libft/ -lft -L minilibx-linux/ -lmlx -lm -lX11 -lXext 
OBJDIR = .objFiles

FILES		= 	main \
				init \
				free \
				free2 \
				raycast \
				parse_input \
				parse_input1 \
				parse_input2 \
				check_validity \
				check_validity1 \
				check_validity2 \
				raycast_limits \
				raycast_init \
				raycast_pixel \
				raycast_set \
				raycast_math \
				raycast_move \
				raycast_wall_collision \
				raycast_minimap \
				raycast_minimap_player \
				raycast_img_loading \
				raycast_sprite \
				raycast_sprite2 \
				raycast_sprite_special \
				raycast_fps \
				raycast_health \
				raycast_move_sprites \
				raycast_move_sprites3 \
				raycast_win \
				raycast_utils \
				raycast_sort \

SRC			= $(FILES:=.c)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

.PHONY: all clean fclean re val run

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) all -C ./libft
	@$(CC) $(OBJ) $(ALL_LIBS) -o $(NAME) libft/libft.a 
	@printf "$(_SUCCESS) $(GREEN)- Executable ready.\n$(RESET)"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@$(RM) valgrind-out.txt
	$(MAKE) clean -C ./libft
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) valgrind-out.txt
	$(MAKE) fclean -C ./libft
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all

val: all
	make -C ./ clean
	valgrind --leak-check=full \
		--show-leak-kinds=all \
        --track-origins=yes \
        --verbose \
        --log-file=valgrind-out.txt \
		./$(NAME) maps/map1.cub
		code valgrind-out.txt

valf: all
	make -C ./ clean
		./$(NAME) maps/map1.cub
		code valgrind-out.txt

supp: all
	make -C ./ clean
	valgrind --memcheck:leak-check=full \
		--show-reachable=yes \
		--suppressions=/nfs/homes/mkoller/PROJECTS/Cub3d/flows_like_water/minimal.supp \
        --log-file=valgrind-out.txt \
		./$(NAME) maps/map1.cub
		code valgrind-out.txt

run:
	./$(NAME) maps/map1.cub

small:
	./$(NAME) maps/map_small.cub

fail:
	./$(NAME) maps/map_fail.cub