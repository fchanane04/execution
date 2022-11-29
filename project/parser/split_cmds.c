/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:32:11 by nel-brig          #+#    #+#             */
/*   Updated: 2022/11/26 01:32:13 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../lexer/lexer.h"

int	get_size_of_tab(t_token *token)
{
	int	count;

	count = 1;
	while (token->next != NULL)
	{
		while (token->next != NULL && token->type != PIPE)
			token = token->next;
		if (token->next != NULL && token->type == PIPE)
		{
			token = token->next;
			count++;
		}
	}
	return (count);
}

t_token	*init_tab(int type, char *s)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		exit(EXIT_FAILURE);
	token->type = type;
	token->index = 0;
	if (s != NULL)
		token->value = strdup(s);
	else
		token->value = NULL;
	token->next = NULL;
	return (token);
}

t_token	*get_tab(t_token *token)
{
	t_token	*tab;

	tab = NULL;
	while (token->next != NULL && token->type != PIPE)
	{
		add_token_back(&tab, init_tab(token->type, token->value));
		token = token->next;
	}
	if (token->next == NULL)
		add_token_back(&tab, init_tab(token->type, token->value));
	return (tab);
}

t_token	**get_token_as_cmd(t_token *token)
{
	t_token	**tab;
	int		i;
	int		size;

	i = 0;
	size = get_size_of_tab(token);
	tab = malloc(sizeof(t_token *) * (size + 1));
	if (!tab)
		exit(EXIT_FAILURE);
	while (i < size)
	{
		tab[i] = get_tab(token);
		while (token->next != NULL && token->type != PIPE)
			token = token->next;
		if (token->next != NULL && token->type == PIPE)
			token = token->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
