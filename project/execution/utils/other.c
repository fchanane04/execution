/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:51:05 by fchanane          #+#    #+#             */
/*   Updated: 2022/11/29 11:19:32 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../minishell.h"

int	list_counter(t_parser *prog)
{
	t_parser	*tmp;
	int			count;

	tmp = prog;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	error_printer(char *bef, char *aft, char *filename)
{
	ft_putstr_fd(bef, 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(aft, 2);
}

void	cleanup_fd(void)
{
	if (var->fd_out > 2)
	{
		close(var->fd_out);
		var->fd_out = 1;
	}
	if (var->fd_in > 2)
	{
		close(var->fd_in);
		var->fd_in = 0;
	}
}
