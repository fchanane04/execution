/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 05:07:00 by fchanane          #+#    #+#             */
/*   Updated: 2022/11/30 13:10:04 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

char	**create_paths(t_env *env)
{
	int		i;
	t_env	*tmp;
	char	**paths;
	char	**no_name;

	i = 0;
	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->line, "PATH", 4))
			break ;
		tmp = tmp->next;
	}
	no_name = ft_split(tmp->line, '=');
	paths = ft_split(no_name[1], ':');
	free(no_name[0]);
	free(no_name[1]);
	free(no_name);
	return (paths);
}

char	*find_path(char **PATHS, char *cmd)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	if (!access(cmd, X_OK))
	{
		free_paths(PATHS);
		return (cmd);
	}
	while (PATHS[i])
	{
		path = ft_strjoin_mod(PATHS[i], cmd);
		if (!access(path, X_OK))
		{
			free_paths(PATHS);
			return (path);
		}
		free(path);
		i++;
	}
	free_paths(PATHS);
	return (NULL);
}

char	**duplicate(t_env *env)
{
	char	**envv;
	t_env	*tmp;
	int		i;

	tmp = env;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	envv = malloc(sizeof(char *) * (i + 1));
	tmp = env;
	i = 0;
	while (tmp)
	{
		envv[i] = ft_strdup(tmp->line);
		i++;
		tmp = tmp->next;
	}
	envv[i] = NULL;
	return (envv);
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

void	exec_single_cmd(t_parser *prog, char *heredoc)
{
	int		pid;
	char	*path;
	char	**envv;
	int		status;

	if (!prog->args)
		return ;
	if (amb_redirect_check(prog) || (file_prep(prog, heredoc) == -1))
		return ;
	pid = fork();
	if (pid == 0)
	{
		//signal(SIGQUIT, sig_child);
		dup2(var->fd_in, 0);
		dup2(var->fd_out, 1);
		path = find_path(create_paths(var->envc), prog->args[0]);
		if (!path)
		{
			var->status = 127;
			write(2, "bash :command not found: ", 25);
			ft_putstr_fd(prog->args[0], 2);
			write(2, "\n", 2);
			exit(var->status);
		}
		envv = duplicate(var->envc);
		if (execve(path, prog->args, envv) <= -1)
		{
			perror("execve");
			exit(1);
		}
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		var->status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
		var->status = WTERMSIG(status) + 128;
	cleanup_fd();
}
