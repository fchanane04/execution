/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:31:01 by nel-brig          #+#    #+#             */
/*   Updated: 2022/11/26 01:31:03 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"
#include "../minishell.h"

void	ft_free_tokens(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (token != NULL)
	{
		tmp = token;
		token = token->next;
		free(tmp->value);
		free(tmp);
	}
}

void	ft_free_tab(t_token **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_free_tokens(tab[i]);
		i++;
	}
	free(tab);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
}

void	free_files(t_files *files)
{
	t_files	*tmp;

	tmp = files;
	while (files != NULL)
	{
		tmp = files;
		files = files->next;
		free(tmp->filename);
		free(tmp);
	}
}

void	ft_free_cmd_table(t_parser *cmd_table)
{
	t_parser	*tmp;

	tmp = cmd_table;
	while (cmd_table != NULL)
	{
		tmp = cmd_table;
		cmd_table = cmd_table->next;
		if (tmp->args != NULL)
			free_tab(tmp->args);
		free_files(tmp->files);
		free(tmp);
	}
}
