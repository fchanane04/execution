/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 05:05:29 by fchanane          #+#    #+#             */
/*   Updated: 2022/11/29 21:51:06 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../minishell.h"

int	check_limits(char *arg)
{
	long long	number;

	number = ft_atoi(arg);
	if ((arg[0] == '-') && (number >= 0))
		return (0);
	if ((arg[0] != '-') && (number <= 0))
		return (0);
	return (1);
}

int	is_valid_num(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (check_limits(arg));
}

void	exit_error(char *arg, char *error)
{
	ft_putstr_fd("bash: exit: ", 1);
	if (arg)
		ft_putstr_fd(arg, 1);
	ft_putstr_fd(error, 1);
}

void	ft_exit(t_parser *prog)
{
	int	flag;

	ft_putstr_fd("exit\n", 1);
	var->status = 0;
	flag = 1;
	if (prog->args[1])
	{
		if (prog->args[1][0] == '0' && prog->args[1][1] == '\0')
			var->status = prog->args[1][0] - 48;
		else if (is_valid_num(prog->args[1]))
		{
		var->status = (unsigned char)ft_atoi(prog->args[1]);
			if (prog->args[2])
			{
				var->status = 1;
				flag = 0;
				exit_error(NULL, EXIT_ERR2);
			}
		}
		else
		{
			var->status = 255;
			exit_error(prog->args[1], EXIT_ERR1);
		}
	}
	if (flag)
		exit(var->status);
}
