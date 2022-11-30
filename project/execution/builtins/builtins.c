/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:45:57 by fchanane          #+#    #+#             */
/*   Updated: 2022/11/30 15:20:01 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../minishell.h"

void	exec_builtin(t_parser *prog, char *heredoc)
{
	if (amb_redirect_check(prog) || (file_prep(prog, heredoc) == -1))
		return ;
	ft_builtins(prog);
}

void	ft_builtins(t_parser *prog)
{
	if (!ft_strcmp(prog->args[0], "echo") || !ft_strcmp(prog->args[0], "ECHO"))
		ft_echo(prog);
	if (!ft_strcmp(prog->args[0], "cd") || !ft_strcmp(prog->args[0], "CD"))
		ft_cd(prog);
	if (!ft_strcmp(prog->args[0], "pwd") || !ft_strcmp(prog->args[0], "PWD"))
		ft_pwd(prog);
	if (!ft_strcmp(prog->args[0], "env") || !ft_strcmp(prog->args[0], "ENV"))
		ft_env(prog);
	if (!ft_strcmp(prog->args[0], "unset") || !ft_strcmp(prog->args[0], "UNSET"))
		ft_unset(prog);
	if (!ft_strcmp(prog->args[0], "export") || !ft_strcmp(prog->args[0], "EXPORT"))
		ft_export(prog);
	if (!ft_strcmp(prog->args[0], "exit") || !ft_strcmp(prog->args[0], "EXIT"))
		ft_exit(prog);
}