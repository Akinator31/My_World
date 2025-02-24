##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for my_world project
##

SRC = $(shell find . -type f -name "*.c")
INCLUDE_H := $(shell find include -type d)
INCLUDE = $(INCLUDE_H:%=-I%)
OBJ = 	$(SRC:%.c=build/%.o)
OBJ_DEBUG = $(SRC:%.c=build-debug/%.o)
OBJ_OPTIMIZATION = $(SRC:%.c=build-optimization/%.o)
CFLAGS += 	-lcsfml-audio -lcsfml-graphics -lcsfml-window \
			-lcsfml-network -lcsfml-system -Wextra -Wall -lm $(INCLUDE)
DEBUG_FLAGS = 	-fsanitize=address -g3 -lcsfml-audio -lcsfml-graphics \
				-lcsfml-window -lcsfml-network -lcsfml-system \
				-Wextra -Wall -lm $(INCLUDE)
OPTIMIZATION_FLAGS = 	-fsanitize=address -g -pg -lcsfml-audio \
						-lcsfml-graphics -lcsfml-window -lcsfml-network \
						-lcsfml-system -Wextra -Wall -lm $(INCLUDE)

NAME = my_world
DEBUG_NAME = debug
OPTIMIZATION_NAME = optimization

.PHONY: all
all: $(NAME)

status:
	@echo "\033[31mBuilding project ...\033[0m";

build/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "\033[31mBuilding $<\033[0m";
	@gcc $(CFLAGS) -c $< -o $@

build-debug/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "\033[31mBuilding $<\033[0m";
	gcc $(DEBUG_FLAGS) -c $< -o $@

build-optimization/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "\033[31mBuilding $<\033[0m";
	gcc $(OPTIMIZATION_FLAGS) -c $< -o $@

.PHONY: $(NAME)
$(NAME): status $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS);
	@echo "\033[32mProject build successfully !\033[0m";

.PHONY: $(DEBUG_NAME)
$(DEBUG_NAME): $(OBJ_DEBUG)
	gcc -o $(DEBUG_NAME) $(OBJ_DEBUG) $(DEBUG_FLAGS)
	@echo "\033[32mProject build successfully !\033[0m";

.PHONY: $(OPTIMIZATION_NAME)
$(OPTIMIZATION_NAME): $(OBJ_OPTIMIZATION)
	gcc -o $(OPTIMIZATION_NAME) $(OBJ_OPTIMIZATION) $(OPTIMIZATION_FLAGS)
	@echo "\033[32mProject build successfully !\033[0m";

.PHONY: clean
clean:
	$(shell find . -type f -name "*.o" -delete)

.PHONY: fclean
fclean:
	@rm -f $(NAME)
	@rm -f $(DEBUG_NAME)
	@rm -f $(OPTIMIZATION_NAME)
	@rm -rf build-optimization
	@rm -rf build-debug
	@rm -rf build
	@echo "\033[32mProject cleaned !$<\033[0m";

.PHONY: re
re: fclean all
