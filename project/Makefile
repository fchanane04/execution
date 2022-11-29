NAME = minishell

USER = fchanane

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

READLINE = -lreadline -L /Users/${USER}/.brew/opt/readline/lib -I /Users/${USER}/.brew/opt/readline/include

CC = gcc

RM = rm -rf

SRC = \
		lexer/lexer.c\
		lexer/lexer_utils.c\
		lexer/token.c\
		lexer/handle_quotes.c\
		lexer/add_herdoc.c\
		lexer/expand.c\
		lexer/expand_utils.c\
		lexer/ft_itoa.c\
		lexer/split_expand.c\
		lexer/ft_split.c\
		lexer/check_quotes.c\
		parser/syntax_error.c\
		parser/print.c\
		parser/split_cmds.c\
		parser/parsing.c\
		parser/parsing_utils.c\
		parser/libft_functions.c\
		parser/free.c\
		parser/files.c\
		env_management.c\
		execution/execution.c\
		execution/handlers/checks_handler.c\
		execution/handlers/heredoc_handler.c\
		execution/handlers/files_handler.c\
		execution/utils/libft1.c\
		execution/utils/libft2.c\
		execution/utils/libft3.c\
		execution/utils/other.c\
		execution/builtins/builtins.c\
		execution/builtins/echo.c\
		execution/builtins/cd.c\
		execution/builtins/pwd.c\
		execution/builtins/env.c\
		execution/builtins/unset.c\
		execution/builtins/export.c\
		execution/builtins/exit.c\
		execution/handlers/memory_handler.c\
		execution/exec_single_cmd.c\
		# execution/heredoc.c\
		# execution/checks.c\
		# execution/builtins/cd.c\
		# execution/builtins/echo.c\
		# execution/builtins/pwd.c\
		# execution/builtins/env.c\
		# execution/builtins/unset.c\
		# execution/builtins/export.c\
		# execution/builtins/builtins.c\
		# execution/builtins/exit.c\
		# execution/memory.c\
		# execution/files.c\
		# execution/execute_single_cmd.c\
		

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) ./main.c ./execution/handlers/signal_handler.c $(READLINE) -o $(NAME)
clean :
		@$(RM) $(OBJ)
fclean :
		@$(RM) $(NAME) $(OBJ)

re : fclean all

.PHONY : all clean fclean