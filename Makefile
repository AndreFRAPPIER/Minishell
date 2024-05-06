##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Make
##

CC	=	gcc

SRC	=		printf/tools/my_put_float.c	\
			printf/tools/my_put_nbr.c	\
			printf/tools/my_putchar.c	\
			printf/tools/my_putstr.c	\
			printf/tools/my_strlen.c	\
			printf/tools/my_put_dtab.c	\
			printf/tools/my_print_e.c	\
			printf/my_printf.c	\
			printf/manage_basics_flags.c	\
			printf/flags_string.c	\
			printf/flags_digits.c	\
			printf/flags_digits_2.c	\
			main.c	\
			error.c	\
			src/my_sh.c	\
			src/my_str_to_word_array.c	\
			src/free_commands.c	\
			src/my_strcmp.c	\
			src/my_concat_param.c	\
			src/commands/len_tab.c	\
			src/commands/find_rank.c	\
			src/commands/my_strcpy.c	\
			src/commands/command_manager.c	\
			src/commands/native_functions.c	\
			src/commands/builtin_function_manager.c	\
			src/commands/cd/cd_main.c	\
			src/commands/cd/cd_home.c	\
			src/commands/cd/cd_last_directory.c	\
			src/commands/cd/change_directory.c	\
			src/commands/env/env_manipulation.c	\
			src/commands/env/setenv_manager.c	\
			src/commands/env/unsetenv_manager.c	\
			src/commands/separator/get_command.c	\
			src/commands/separator/separator_manager.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I lib/ -W

NAME	=	mysh

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(SRC) $(CFLAGS)
		make clean

debug:	CFLAGS += -g -fsanitize=address,leak,undefined
debug:	re

clean	:
	rm -f $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	:	fclean all
