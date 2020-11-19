##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c			\
		src/my_defender.c		\
		src/init.c			\
		src/init_tabs.c			\
		src/display.c			\
		src/init_text.c			\
		src/how_to_play.c		\
		src/init_textures.c		\
		src/init_sprites.c		\
		src/init_rectangles.c		\
		src/destroy_ressources.c	\
		src/manage_mouse.c		\
		src/anim_enemies.c		\
		src/place_obstacles.c		\
		src/init_obstacles.c		\
		src/destroy_obstacles.c		\
		src/display_in_order.c		\
		src/towers_attack.c		\
		src/anim_towers.c		\
		src/manage_pause.c		\
		src/check_click.c		\
		src/init_scales.c		\
		src/synopsis.c			\
		src/enemies_attack.c		\
		src/init_buttons_files.c	\
		src/convert_int_str.c		\
		src/display_life.c		\
		src/init_music.c		\
		src/info.c			\
		src/check_info_buttons.c	\
		src/reset_all.c			\
		src/init_player_life.c		\
		src/manage_prize.c		\
		src/manage_end.c		\
		src/check_click_end.c		\
		src/init_end.c			\
		src/display_best_score.c	\
		src/draw_elems.c		\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-Wshadow -I ./include

LIB	=	-L ./lib/my -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system  -lcsfml-audio -lm

NAME	=	my_defender

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	make -C ./lib/my clean
	rm -f $(OBJ)
	rm -f *.gcno *.gcda

fclean:	clean
	make -C ./lib/my fclean
	rm -f $(NAME)

re:	fclean all
	make -C ./lib/my re
