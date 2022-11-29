/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:46:26 by fchanane          #+#    #+#             */
/*   Updated: 2022/11/29 21:38:48 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../minishell.h"

int	builtin_check(char *cmd)
{
	int	check;

	check = 0;
	if (!ft_strncmp(cmd, "echo", ft_strlen("echo")))
		check = 1;
	if (!ft_strncmp(cmd, "cd", ft_strlen("cd")))
		check = 1;
	if (!ft_strncmp(cmd, "pwd", ft_strlen("pwd")))
		check = 1;
	if (!ft_strncmp(cmd, "env", ft_strlen("env")))
		check = 1;
	if (!ft_strncmp(cmd, "unset", ft_strlen("unset")))
		check = 1;
	if (!ft_strncmp(cmd, "export", ft_strlen("export")))
		check = 1;
	if (!ft_strncmp(cmd, "exit", ft_strlen("exit")))
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
