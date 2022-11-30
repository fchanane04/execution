/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:46:26 by fchanane          #+#    #+#             */
/*   Updated: 2022/11/30 15:22:27 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../minishell.h"

int	builtin_check(char *cmd)
{
	int	check;

	check = 0;
	if (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "ECHO"))
		check = 1;
	if (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "CD"))
		check = 1;
	if (!ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "PWD"))
		check = 1;
	if (!ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "ENV"))
		check = 1;
	if (!ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "UNSET"))
		check = 1;
	if (!ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "EXPORT"))
		check = 1;
	if (!ft_strcmp(cmd, "exit") || !ft_strcmp(cmd, "EXIT"))
		check = 1;
	return (check);
}

int	exec_type_check(t_parser *prog)
{
	int			count;
	int			check;

	count = list_counter(prog);
	if (count == 1)
	{
		check = 1;
		if (prog->args && builtin_check(prog->args[0]))
			check = 0;
	}
	else
		check = 2;
	return (check);
}

int	amb_redirect_check(t_parser *prog)
{
	t_files	*tmp;

	tmp = prog->files;
	while (tmp)
	{
		if (tmp->type == AMB)
		{
			ft_putstr_fd("bash: ", 2);
			ft_putstr_fd(tmp->filename, 2);
			ft_putstr_fd(": ambiguous redirect", 2);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
