/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:31:26 by nel-brig          #+#    #+#             */
/*   Updated: 2022/11/26 01:31:37 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"
#include "../minishell.h"

int	get_size_of_files(t_token *tab, int type)
{
	int	count;

	count = 0;
	while (tab != NULL)
	{
		if ((int)tab->type == type)
			count++;
		tab = tab->next;
	}
	return (count);
}

int	get_size_of_words(t_token *tab)
{
	int	count;

	count = 0;
	while (tab != NULL)
	{
		if (tab->type == R_RED || tab->type == L_RED
			|| tab->type == DEL || tab->type == APP)
		{
			tab = tab->next;
			if (tab == NULL)
				break ;
		}
		else if (tab->type == WORD)
			count++;
		tab = tab->next;
	}
	return (count);
}

void	init_args(t_token *tab, char **s, int *i)
{
	if (tab->value != NULL)
		s[*i] = strdup(tab->value);
	else
		s[*i] = NULL;
	*i += 1;
}

void	assign_null(t_parser *cmd_table, int *index)
{
	if (cmd_table->args != NULL)
		cmd_table->args[*index] = NULL;
	cmd_table->next = NULL;
}
