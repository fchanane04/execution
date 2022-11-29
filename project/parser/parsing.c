/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:31:18 by nel-brig          #+#    #+#             */
/*   Updated: 2022/11/26 01:31:20 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"
#include "../minishell.h"

void	fill_args_herdoc(t_token *tab, t_parser *cmd_table, int *index)
{
	int		type;
	t_token	*tmp;

	tmp = tab;
	while (tmp != NULL)
	{
		type = tmp->type;
		if (type == R_RED || type == L_RED || type == APP || type == DEL)
			tmp = tmp->next;
		else if (type == WORD)
			init_args(tmp, cmd_table->args, index);
		tmp = tmp->next;
	}
}

char	**ft_allocate(int size)
{
	char	**s;

	s = NULL;
	if (size != 0)
	{
		s = malloc(sizeof(char *) * (size + 1));
		if (!s)
			exit(EXIT_FAILURE);
	}
	return (s);
}

t_parser	*init_cmd_table(t_token *tab)
{
	t_parser	*cmd_table;
	int			size;
	int			index;

	index = 0;
	cmd_table = malloc(sizeof(t_parser));
	if (!cmd_table)
		exit(EXIT_FAILURE);
	size = get_size_of_words(tab);
	cmd_table->args = ft_allocate(size);
	fill_args_herdoc(tab, cmd_table, &index);
	cmd_table->files = fill_files(tab);
	assign_null(cmd_table, &index);
	return (cmd_table);
}

void	add_cmd_back(t_parser **cmd_table, t_parser *new)
{
	t_parser	*tmp;

	tmp = NULL;
	if (*cmd_table == NULL)
	{
		*cmd_table = new;
		return ;
	}
	tmp = *cmd_table;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_parser	*parse_cmd(t_token **tab)
{
	t_parser	*cmd_table;
	int			i;
	int			j;

	i = 0;
	j = 0;
	cmd_table = NULL;
	while (tab[i] != NULL)
	{
		add_cmd_back(&cmd_table, init_cmd_table(tab[i]));
		i++;
	}
	return (cmd_table);
}
