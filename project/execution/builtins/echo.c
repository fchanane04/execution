/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:55:18 by fchanane          #+#    #+#             */
/*   Updated: 2022/11/29 21:43:59 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../minishell.h"

int	check_opt(char *opt)
{
	int	i;

	i = 0;
	if (!opt)
		return (0);
	if (opt[i] != '-')
		return (0);
	i++;
	if (!opt[i])
		return (0);
	while (opt[i])
	{
		if (opt[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_echo(t_parser *prog)
{
	int	i;
	int	endl;

	i = 1;
	endl = 1;
	while (check_opt(prog->args[i]))
	{
		i++;
		endl = 0;
	}
	while (prog->args[i])
	{
		ft_putstr_fd(prog->args[i], var->fd_out);
		if (prog->args[i + 1])
			ft_putstr_fd(" ", var->fd_out);
		i++;
	}
	if (endl)
		ft_putstr_fd("\n", var->fd_out);
	if (var->fd_out > 1)
		close(var->fd_out);
	var->status = 0;
}
