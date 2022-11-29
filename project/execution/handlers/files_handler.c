/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:18:13 by fchanane          #+#    #+#             */
/*   Updated: 2022/11/29 21:39:42 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../minishell.h"

int	isdir(char *fileName)
{
	struct stat	path;

	stat(fileName, &path);
	return (S_ISREG(path.st_mode));
}

int	infile_handler(char *filename)
{
	if (var->fd_in > 2)
		close(var->fd_in);
	var->fd_in = open(filename, O_RDONLY, 0777);
	if (var->fd_in == -1)
	{
		error_printer(BASH_ERR, ": ", filename);
		perror("");
		var->status = 1;
		return (-1);
	}
	return (1);
}

int	outfile_handler(char *filename)
{
	if (var->fd_out > 2)
		close(var->fd_out);
	var->fd_out = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (var->fd_out == -1)
	{
		error_printer(BASH_ERR, ": ", filename);
		perror("");
		var->status = 1;
		return (-1);
	}
	return (1);
}

int	append_handler(char *filename)
{
	if (var->fd_out > 2)
		close(var->fd_out);
	var->fd_out = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (var->fd_out == -1)
	{
		error_printer(BASH_ERR, ": ", filename);
		perror("");
		var->status = 1;
		return (-1);
	}
	return (1);
}

int	file_prep(t_parser *prog, char *heredoc)
{
	t_files	*tmp;
	int		err;

	tmp = prog->files;
	err = 1;
	while (tmp)
	{
		if (err == -1)
			return (-1);
		if (tmp->type == IN)
			err = infile_handler(tmp->filename);
		if (tmp->type == HEREDOC)
			var->fd_in = -404;
		if (tmp->type == OUT)
			err = outfile_handler(tmp->filename);
		if (tmp->type == AP)
			err = append_handler(tmp->filename);
		tmp = tmp->next;
	}
	err = re_init_heredoc(heredoc, var->fd_in, err);
	return (err);
}
