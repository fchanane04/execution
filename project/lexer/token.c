/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:31:34 by nel-brig          #+#    #+#             */
/*   Updated: 2022/11/25 16:31:36 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

char	*get_env(char *str)
{
	int		i;
	char	*s;
	t_env	*tmp;	

	i = 0;
	s = NULL;
	tmp = var->envc;
	while (tmp != NULL)
	{
		if (strncmp(tmp->line, str, ft_strlen(str)) == 0
			&& tmp->line[ft_strlen(str)] == '=')
		{
			s = strdup(tmp->line + ft_strlen(str) + 1);
			free(str);
			str = NULL;
			return (s);
		}
		tmp = tmp->next;
	}
	free(str);
	str = NULL;
	return (NULL);
}

t_token	*init_token(int type, char *s, int *flag, int expand)
{
	t_token		*token;
	static int	i;

	if (*flag == 0)
	{
		i = 0;
		*flag = 1;
	}
	token = malloc(sizeof(t_token));
	if (!token)
		exit(EXIT_FAILURE);
	token->expand = 0;
	if (expand == 1)
		token->expand = 1;
	token->type = type;
	if (s != NULL)
		token->value = strdup(s);
	else
		token->value = NULL;
	token->index = i;
	token->next = NULL;
	i++;
	free(s);
	s = NULL;
	return (token);
}

void	add_token_back(t_token **token, t_token *new)
{
	t_token	*tmp;

	if (!*token)
	{
		*token = new;
		return ;
	}
	tmp = *token;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
