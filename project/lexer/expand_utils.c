/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:31:52 by nel-brig          #+#    #+#             */
/*   Updated: 2022/11/25 16:31:54 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*handle_status(t_lexer *lexer)
{
	char	*s;

	s = NULL;
	lexer_advance(lexer);
	return (ft_itoa(var->status));
}

void	skip_alnum(t_lexer *lexer)
{
	while (ft_isalnum(lexer->c) == 1 && lexer->c != '\0')
		lexer_advance(lexer);
}

char	*get_string_to_expand(t_lexer *lexer)
{
	char	*s;
	char	*str;

	s = NULL;
	str = NULL;
	while (ft_isalnum(lexer->c) || lexer->c == '_')
	{
		s = get_char_as_string(lexer->c);
		str = ft_strjoin(str, s);
		free(s);
		s = NULL;
		lexer_advance(lexer);
	}
	return (str);
}

char	*dollar(t_lexer *lexer, t_token **token, int *flag)
{
	char	*s;
	char	c;

	s = NULL;
	c = lexer->line[lexer->i + 1];
	if (ft_is_digit(c) == 1)
	{
		lexer_advance(lexer);
		lexer_advance(lexer);
		if (c == '0')
			return (strdup("minishell"));
		return (NULL);
	}
	else if (lexer->c == '$' && ft_isalnum(c) != 1 && c != '$')
	{
		lexer_advance(lexer);
		if (lexer->c == '?')
			return (handle_status(lexer));
		return (get_char_as_string('$'));
	}
	else if (lexer->c == '$' && red_or_pipe(lexer->line[lexer->i + 1]) != 1)
		return (expand_dollar(lexer, token, flag));
	return (NULL);
}
