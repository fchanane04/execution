/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:45:57 by fchanane          #+#    #+#             */
/*   Updated: 2022/11/29 19:14:49 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../minishell.h"

void	exec_builtin(t_parser *prog, char *heredoc)
{
	if (amb_redirect_check(prog) || (file_prep(prog, heredoc) == -1))
		return ;
	if (!ft_strncmp(prog->args[0], "echo", ft_strlen(prog->args[0])))
		ft_echo(prog);
	if (!ft_strncmp(prog->args[0], "cd", ft_strlen(prog->args[0])))
		ft_cd(prog);
	if (!ft_strncmp(prog->args[0], "pwd", ft_strlen(prog->args[0])))
		ft_pwd(prog);
	if (!ft_strncmp(prog->args[0], "env", ft_strlen(prog->args[0])))
		ft_env(prog);
	if (!ft_strncmp(prog->args[0], "unset", ft_strlen(prog->args[0])))
		ft_unset(prog);
	if (!ft_strncmp(prog->args[0], "export", ft_strlen(prog->args[0])))
		ft_export(prog);
	if (!ft_strncmp(prog->args[0], "exit", ft_strlen(prog->args[0])))
		ft_exit(prog);
}
