##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for my_world project
##

SRC_MAIN    =     src/main.c

SRC_ENGINE  =     src/engine/utils/engine_utils.c \
                  src/engine/engine.c

SRC_EVENT   =     src/event/event_manager.c \
                  src/event/utils/event_utils.c

SRC_ENTITY  =     src/entity/entity.c \
                  src/entity/utils/entity_utils.c

SRC_ANIMATIONS    =     src/animations/rotating/rotating.c \
                        src/animations/bouncing/bouncing.c \
                        src/animations/button/button_anim.c \

SRC_SCENES  =     src/scenes/main_menu/main_menu.c \
                  src/scenes/scenes_manager.c \
                  src/scenes/game/game_scene.c \
                  src/scenes/settings_menu/settings_menu.c \
                  src/scenes/creat_map/creat_map.c \
                  src/scenes/utils/scenes_utils.c

SRC_RESSOURCES    =     src/ressources/ressources_manager.c

SRC_UTILS   =     src/utils/check_screen_size.c \
                  src/utils/set_sprite_hover.c \
                  src/utils/create_window.c \
                  src/utils/get_scene_by_id.c \
                  src/utils/create_array_int.c \
                  src/utils/create_2d_map.c \
                  src/utils/help_display.c \
                  src/utils/switch_music.c \
                  src/utils/get_random_pos.c \
                  src/utils/multi_array_vector.c \
                  src/utils/mute_or_unmute_music.c \
                  src/utils/is_mouse_on_sprite.c \
                  src/utils/draw_2d_map.c \
                  src/utils/get_input_on_map.c \
                  src/utils/alloc_error.c \

SRC_LIB_MY_LIST   =     lib/my_list/remove_data.c \
                        lib/my_list/info_list.c \
                        lib/my_list/add_data.c

SRC_LIB_SECURED   =     lib/secured/hash_table/creat_hash_table.c \
                        lib/secured/hash_table/hash_table_delete.c \
                        lib/secured/hash_table/hash_table_search.c \
                        lib/secured/hash_table/hash_table_dump.c \
                        lib/secured/hash_table/hash_table_insert.c \
                        lib/secured/tools/my_getnbr.c \
                        lib/secured/hash_table/delete_hash_table.c \
                        lib/secured/tools/get_str_in_nbr.c \
                        lib/secured/tools/my_nbrlen.c \
                        lib/secured/hash_function/other_hash_function.c \
                        lib/secured/tools/abs.c \
                        lib/secured/tools/my_nbr_to_str.c

SRC_LIB_MY_LIB    =     lib/my_lib/my_putstr.c \
                        lib/my_lib/my_put_nbr.c \
                        lib/my_lib/my_strlen.c \
                        lib/my_lib/my_strcpy.c \
                        lib/my_lib/my_putchar.c \
                        lib/my_lib/my_strnum.c \
                        lib/my_lib/my_strlowcase.c \
                        lib/my_lib/my_strcmp.c

SRC_LIB_MY_PRINTF =     lib/my_printf/mini_printf.c

SRC   =     $(SRC_MAIN) \
            $(SRC_ENGINE) \
            $(SRC_EVENT) \
            $(SRC_ENTITY) \
            $(SRC_ANIMATIONS) \
            $(SRC_SCENES) \
            $(SRC_RESSOURCES) \
            $(SRC_UTILS) \
            $(SRC_LIB_MY_LIST) \
            $(SRC_LIB_SECURED) \
            $(SRC_LIB_MY_LIB) \
            $(SRC_LIB_MY_PRINTF)

INCLUDE_H   =     include/lib \
                  include/my_world

INCLUDE     =   $(INCLUDE_H:%=-I%)

OBJ   = 	$(SRC:%.c=build/%.o)

OBJ_DEBUG   =     $(SRC:%.c=build-debug/%.o)

OBJ_OPTIMIZATION  =     $(SRC:%.c=build-optimization/%.o)

CFLAGS      += 	-lcsfml-audio -lcsfml-graphics -lcsfml-window \
			-lcsfml-network -lcsfml-system -Wextra -Wall -lm $(INCLUDE)
DEBUG_FLAGS =     -fsanitize=address -g3 -lcsfml-audio -lcsfml-graphics \
			      -lcsfml-window -lcsfml-network -lcsfml-system \
			      -Wextra -Wall -lm $(INCLUDE)
OPTIMIZATION_FLAGS      = 	-fsanitize=address -g -pg -lcsfml-audio \
				      -lcsfml-graphics -lcsfml-window -lcsfml-network \
				      -lcsfml-system -Wextra -Wall -lm $(INCLUDE)

NAME  =      my_world

DEBUG_NAME  =      debug

OPTIMIZATION_NAME =     optimization

all:  $(NAME)

status:
	@echo "\033[31mBuilding project ...\033[0m";

build/%.o:  %.c
	@mkdir -p $(dir $@)
	@echo "\033[31mBuilding $<\033[0m";
	@$(CC) $(CFLAGS) -c $< -o $@

build-debug/%.o:  %.c
	@mkdir -p $(dir $@)
	@echo "\033[31mBuilding $<\033[0m";
	$(CC) $(DEBUG_FLAGS) -c $< -o $@

build-optimization/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "\033[31mBuilding $<\033[0m";
	$(CC) $(OPTIMIZATION_FLAGS) -c $< -o $@

$(NAME):    status $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS);
	@echo "\033[32mProject build successfully !\033[0m";

$(DEBUG_NAME):    $(OBJ_DEBUG)
	$(CC) -o $(DEBUG_NAME) $(OBJ_DEBUG) $(DEBUG_FLAGS)
	@echo "\033[32mProject build successfully !\033[0m";

$(OPTIMIZATION_NAME):   $(OBJ_OPTIMIZATION)
	$(CC) -o $(OPTIMIZATION_NAME) $(OBJ_OPTIMIZATION) $(OPTIMIZATION_FLAGS)
	@echo "\033[32mProject build successfully !\033[0m";

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(DEBUG_NAME)
	@$(RM) $(OPTIMIZATION_NAME)
	@$(RM) -r build-optimization
	@$(RM) -r build-debug
	@$(RM) -r build
	@echo "\033[32mProject cleaned !\033[0m";

re:   fclean all

.PHONY:     all clean fclean re
