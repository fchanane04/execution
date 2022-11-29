/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_herdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:32:37 by nel-brig          #+#    #+#             */
/*   Updated: 2022/11/25 16:32:38 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

char	*get_string_inside_quotes(t_lexer *lexer)
{
	char	c;
	char	*s;
	char	*str;

	c = lexer->c;
	s = NULL;
	str = NULL;
	lexer_advance(lexer);
	while (lexer->c != c)
	{
		s = get_char_as_string(lexer->c);
		str = ft_strjoin(str, s);
		free(s);
		s = NULL;
		lexer_advance(lexer);
	}
	lexer_advance(lexer);
	return (str);
}

char	*get_string(t_lexer *lexer)
{
	char	*s;
	char	*str;

	s = NULL;
	str = NULL;
	while (is_space(lexer->c) != 0 && lexer->c != '\0'
		&& is_quote(lexer->c) != 0 && red_or_pipe(lexer->c) != 1)
	{
		s = get_char_as_string(lexer->c);
		str = ft_strjoin(str, s);
		free(s);
		s = NULL;
		lexer_advance(lexer);
	}
	return (str);
}

void	add_herdoc_as_token(t_token **token, int *flag)
{
	char	*s;

	s = NULL;
	s = strdup("<<");
	add_token_back(token, init_token(DEL, s, flag, -1));
}

char	*get_heredoc_name(t_lexer *lexer)
{
	char	*s;
	char	*str;

	s = NULL;
	str = NULL;
	while (is_space(lexer->c) != 0 && lexer->c != '\0'
		&& red_or_pipe(lexer->c) != 1)
	{
		if (lexer->c == '\'' || lexer->c == '"')
			s = get_string_inside_quotes(lexer);
		else
			s = get_string(lexer);
		if (s != NULL)
		{
			str = ft_strjoin(str, s);
			free(s);
			s = NULL;
		}
	}
	return (str);
}

void	add_herdoc(t_lexer *lexer, t_token **token, int *flag)
{
	char	*s;
	char	*str;

	s = NULL;
	str = NULL;
	lexer_advance(lexer);
	lexer_advance(lexer);
	ft_skip_whitespaces(lexer);
	add_herdoc_as_token(token, flag);
	if (lexer->c == '$' && is_quote(lexer->line[lexer->i + 1]) == 0)
		lexer_advance(lexer);
	str = get_heredoc_name(lexer);
	if (str != NULL)
		add_token_back(token, init_token(WORD, str, flag, -1));
}
