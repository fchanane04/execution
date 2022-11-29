/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:30:47 by nel-brig          #+#    #+#             */
/*   Updated: 2022/11/25 16:30:49 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

typedef struct s_lexer
{
	char	c;
	int		i;
	char	*line;
}t_lexer;

enum	e_type{
	R_RED,
	L_RED,
	PIPE,
	WORD,
	DEL,
	APP,
};

typedef struct s_token	t_token;

struct s_token
{
	enum e_type	type;
	int			expand;
	char		*value;
	int			index;
	t_token		*next;
};

char	*get_char_as_string(char c);
void	add_herdoc(t_lexer *lexer, t_token **token, int *flag);
void	add_token_back(t_token **head, t_token *new);
void	quotes(t_token *head);
int		check_quotes(char *line);
t_token	*init_tab(int type, char *s);
void	print_tab(t_token **tab);
t_token	**get_token_as_cmd(t_token *token);
t_lexer	*init_lexer(char *line);
void	print_tokens(t_token *token);
t_token	*get_token(t_lexer *lexer);
int		get_size_of_tab(t_token *token);
int		ft_isalnum(int c);
void	lexer_advance(t_lexer *lexer);
char	*get_str_inside_quotes(t_lexer *lexer, t_token **token, int *flag);
void	add_token_back(t_token **token, t_token *new);
t_token	*init_token(int type, char *s, int *flag, int expand);
char	*single_quote(t_lexer *lexer);
char	*double_quote(t_lexer *lexer, t_token **token, int *flag);
char	*collect_string_check_dollar(t_lexer *lexer,
			t_token **token, int *flag);
char	*expand_dollar(t_lexer *lexer, t_token **token, int *flag);
int		syntax(t_token *token);
void	ft_skip_whitespaces(t_lexer *lexer);
void	lexer_advance(t_lexer *lexer);
int		special_characters(char c);
int		red_or_pipe(char c);
t_lexer	*init_lexer(char *line);
char	*get_env(char *str);
char	*dollar(t_lexer *lexer, t_token **token, int *flag);
char	*ft_itoa(int n);
void	skip(t_lexer *lexer, char c);
int		is_space(char c);
int		is_quote(char c);
int		is_whitespaces(char c);
char	**ft_split(char *s, char c);
char	*handle_spaces(char *expand, t_token **token, int *flag);
char	*get_string_to_expand(t_lexer *lexer);

#endif
