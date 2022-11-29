/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:32:24 by nel-brig          #+#    #+#             */
/*   Updated: 2022/11/25 16:32:25 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

char	*collect_string(t_lexer *lexer)
{
	char	*s;
	char	*str;

	s = NULL;
	str = NULL;
	while (lexer->c != '\'')
	{
		s = get_char_as_string(lexer->c);
		str = ft_strjoin(str, s);
		free(s);
		s = NULL;
		lexer_advance(lexer);
	}
	return (str);
}

char	*collect_string_check_dollar(t_lexer *lexer, t_token **token, int *flag)
{
	char	*s;
	char	*s1;
	char	*str;

	s = NULL;
	str = NULL;
	s1 = NULL;
	while (lexer->c != '"' && lexer->c != '\0')
	{
		if (lexer->c == '$')
			s = expand_dollar(lexer, token, flag);
		else
		{
			s = get_char_as_string(lexer->c);
			lexer_advance(lexer);
		}
		if (s != NULL)
			str = ft_strjoin(str, s);
		if (s != NULL)
		{
			free(s);
			s = NULL;
		}
	}
	return (str);
}

char	*single_quote(t_lexer *lexer)
{
	char	*str;

	str = NULL;
	lexer_advance(lexer);
	if (lexer->c != '\'' )
		str = collect_string(lexer);
	lexer_advance(lexer);
	return (str);
}

char	*double_quote(t_lexer *lexer, t_token **token, int *flag)
{
	char	*s;

	s = NULL;
	lexer_advance(lexer);
	s = collect_string_check_dollar(lexer, token, flag);
	lexer_advance(lexer);
	return (s);
}

char	*get_str_inside_quotes(t_lexer *lexer, t_token **token, int *flag)
{
	char	*s;

	s = NULL;
	if (lexer->c == '"')
		s = double_quote(lexer, token, flag);
	else if (lexer->c == '\'')
		s = single_quote(lexer);
	return (s);
}
