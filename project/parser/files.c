/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:15:48 by nel-brig          #+#    #+#             */
/*   Updated: 2022/11/26 16:15:49 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"
#include "../minishell.h"

int	file_type(int type)
{
	if (type == R_RED)
		return (OUT);
	else if (type == L_RED)
		return (IN);
	else if (type == APP)
		return (AP);
	else if (type == DEL)
		return (HEREDOC);
	return (0);
}

t_files	*init_file(t_token *tab, int type)
{
	t_files	*file;

	file = malloc(sizeof(t_files));
	if (!file)
		return (NULL);
	file->type = file_type(type);
	file->filename = strdup(tab->value);
	file->next = NULL;
	return (file);
}

void	add_file_back(t_files **files, t_files *new)
{
	t_files	*tmp;

	if (!*files)
	{
		*files = new;
		return ;
	}
	tmp = *files;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_files	*fill_files(t_token *tab)
{
	t_token	*tmp;
	int		type;
	t_files	*files;

	tmp = tab;
	files = NULL;
	while (tmp != NULL)
	{
		type = tmp->type;
		if (type == R_RED || type == L_RED || type == APP || type == DEL)
		{
			tmp = tmp->next;
			add_file_back(&files, init_file(tmp, type));
		}
		tmp = tmp->next;
	}
	return (files);
}
