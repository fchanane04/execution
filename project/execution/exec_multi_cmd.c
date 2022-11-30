/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 05:07:43 by fchanane          #+#    #+#             */
/*   Updated: 2022/11/30 13:12:00 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	exec_multi_cmd(t_parser *prog, char **heredocs)
{
	t_parser	*tmp;
	int			pid;
	int			fd;
	int			pip[2];
	int			status;
	int			i;
	char		*path;
	char		**envv;

	tmp = prog;
	i = 0;
	fd = -1;
	while (tmp)
	{	
		if (amb_redirect_check(prog) || (file_prep(prog, heredocs[i]) == -1) || !tmp->args)
			tmp = tmp->next;
		else
		{
			pipe(pip);
			pid = fork();
			if (builtin_check(tmp->args[0]))
			{
				if (pid != 0)
				{
					close(pip[0]);
					if (fd != -1)
						close(fd);
					if (var->fd_in > 2)
						close(var->fd_in);
					if (var->fd_out == 1 && tmp->next)
						var->fd_out = pip[1];
					ft_builtins(tmp);
				}
				//waitpid(pid, &status, 0);
			}
			else
			{
				if (pid == 0)
				{
					signal(SIGQUIT, sig_child);
					if (var->fd_in > 2)
						dup2(var->fd_in, 0);
					else
					{
						if (fd != -1)
							dup2(fd, 0);
					}
					if (var->fd_out > 2)
						dup2(var->fd_out, 1);
					if (var->fd_out == 1 && tmp->next)
						dup2(pip[1], 1);
					path = find_path(create_paths(var->envc), tmp->args[0]);
					if (!path)
					{
						var->status = 127;
						write(2, "bash :command not found: ", 25);
						ft_putstr_fd(prog->args[0], 2);
						write(2, "\n", 2);
						exit(var->status);
					}
					envv = duplicate(var->envc);
					if (execve(path, tmp->args, envv) <= -1)
					{
						perror("execve");
						exit(1);
					}
				}
					waitpid(-1, &status, 0);
					if (WIFEXITED(status))
						var->status = WEXITSTATUS(status);
					if (WIFSIGNALED(status))
						var->status = WTERMSIG(status) + 128;
					cleanup_fd();
			}
		}
		signal(SIGQUIT, SIG_DFL);
		fd = pip[0];
		cleanup_fd();
		tmp = tmp->next;
	}
}
