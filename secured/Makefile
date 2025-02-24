##
## EPITECH PROJECT, 2024
## B-CPE-110-TLS-1-1-secured-alexy.legrand
## File description:
## Makefile
##

SRC_HASH_TABLE =	hash_table/creat_hash_table.c 	\
					hash_table/hash_table_dump.c 	\
					hash_table/delete_hash_table.c 	\
					hash_table/hash_table_delete.c 	\
					hash_table/hash_table_insert.c  \
					hash_table/hash_table_search.c 	\

SRC_HASH =	hash_function/other_hash_function.c 	\

SRC_TOOLS = tools/my_strcpy.c 	\
			tools/my_strcmp.c 	\
			tools/my_nbrlen.c 	\
			tools/my_nbr_to_str.c 	\
			tools/get_str_in_nbr.c 	\
			tools/my_getnbr.c \
			tools/abs.c 	\

SRC_FLAG= 	mini_printf.c	\
			my_put_nbr.c	\
			my_putchar.c	\
			my_putstr.c	\
			my_strlen.c	\

SRC_FLAG:=	$(addprefix mini_printf/, $(SRC_FLAG))

NAME = libhashtable.a

OBJ_FLAG:=	$(SRC_FLAG:.c=.o)

OBJ_HASH_TABLE = $(SRC_HASH_TABLE:.c=.o)

OBJ_HASH = $(SRC_HASH:.c=.o)

OBJ_TOOLS = $(SRC_TOOLS:.c=.o)

all :	 $(OBJ_HASH_TABLE) $(OBJ_TOOLS) $(OBJ_FLAG) $(OBJ_HASH)
		ar rc $(NAME) $(OBJ_HASH_TABLE) $(OBJ_TOOLS) $(OBJ_FLAG) $(OBJ_HASH)

clean:
			rm -f $(OBJ_HASH_TABLE) $(OBJ_TOOLS) $(OBJ_FLAG) $(OBJ_HASH)
			rm -f ./*gcno
			rm -f ./*gcda

fclean: clean
				rm -f $(NAME)

re : fclean all
