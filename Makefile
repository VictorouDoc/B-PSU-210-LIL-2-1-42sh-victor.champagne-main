##
## EPITECH PROJECT, 2022
## B-PSU-101-LIL-1-1-minishell1-shailendra.blondel
## File description:
## Makefile
##

MINISHELL	=	src_shell

BUILTINS	=	/builtins

TOOLS	=	/tools

SRC	=	$(MINISHELL)/main.c \
		$(MINISHELL)/initializer/initialize.c \
		$(MINISHELL)/initializer/init.c \
		$(MINISHELL)/initializer/redirections.c \
		$(MINISHELL)/shell/shell.c \
		$(MINISHELL)/shell/get_pipe.c \
		$(MINISHELL)/shell/get_ampersand.c	\
		$(MINISHELL)$(TOOLS)/my_tablen.c \
		$(MINISHELL)$(TOOLS)/signal.c \
		$(MINISHELL)$(TOOLS)/write_error.c \
		$(MINISHELL)$(TOOLS)/my_str_isupper.c \
		$(MINISHELL)$(TOOLS)/error_handle.c \
		$(MINISHELL)$(TOOLS)/str_check.c \
		$(MINISHELL)$(TOOLS)/my_getnbr.c \
		$(MINISHELL)$(TOOLS)/check_if_digit.c \
		$(MINISHELL)$(TOOLS)/free.c \
		$(MINISHELL)$(TOOLS)/shell_checker.c \
		$(MINISHELL)/parsing/parse_commands.c \
		$(MINISHELL)/parsing/parsing.c \
		$(MINISHELL)/parsing/placement.c \
		$(MINISHELL)/parsing/execve_parsing.c \
		$(MINISHELL)$(BUILTINS)/get_builtins.c \
		$(MINISHELL)$(BUILTINS)/my_cd.c \
		$(MINISHELL)$(BUILTINS)/change_dir.c \
		$(MINISHELL)$(BUILTINS)/cd_directives.c \
		$(MINISHELL)$(BUILTINS)/cd_path.c \
		$(MINISHELL)$(BUILTINS)/my_env.c \
		$(MINISHELL)$(BUILTINS)/my_setenv.c \
		$(MINISHELL)$(BUILTINS)/setenv_tool.c \
		$(MINISHELL)$(BUILTINS)/my_unsetenv.c \
		$(MINISHELL)$(BUILTINS)/my_exit.c \
		$(MINISHELL)/commands/get_execve.c \
		$(MINISHELL)/commands/get_exe.c \
		$(MINISHELL)/commands/check_execve.c \
		$(MINISHELL)/commands/get_my_path.c \

OBJ	=	$(SRC:.c=.o)

CC	=	@gcc -g

NAME	=	42sh

LIB	=	-L ./lib/my/

CFLAGS	=	-I include -Wall -Wextra

LIBC	=	-lmy

all:	$(NAME)

$(NAME):	build_lib $(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB) $(LIBC)

build_lib:
	@make -s all -C ./lib/my/

clean:
	@make -s clean -C ./lib/my/
	@rm -f $(OBJ)
	@rm -f vgcore.*

fclean: clean
	@make -s fclean -C ./lib/my/
	@rm -f $(NAME)
	@rm -f vgcore.*

re:	fclean all
