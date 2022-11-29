/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 05:02:24 by fchanane          #+#    #+#             */
/*   Updated: 2022/11/29 22:02:26 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../minishell.h"

int	valid_name(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '_' && !ft_isalpha(str[i]))
		return (0);
	i++;
	while (str[i])
	{
		if (str[i] != '_' && !ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	unset_error(char *str)
{
	ft_putstr_fd("bash: unset: `", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\': not a valid identifier\n", 1);
}

t_env	*unset_inside(t_env *envc)
{
	// t_env	*save;
	// t_env	*current;
	// t_env	*tmp;

	// save = envc;
	// current = save->next;
	// while (current)
	// {
	// 	tmp = current->next;
	// 	if (ft_strncmp(current->line, )) |
	// }
	//khas n3awdha
}

void	ft_unset(t_parser *prog)
{
	int		i;
	t_env	*tmp;
	t_env	*save;

	i = 1;
	var->status = 0;
	if (!prog->args[i])
		return ;
	while (prog->args[i])
	{
		if (prog->args[i][0] == '#')
			return ;
		if (!valid_name(prog->args[i]))
			unset_error(prog->args[i]);
		tmp = var->envc;
		while (var->envc
			&& !ft_strncmp(tmp->line, prog->args[i], ft_strlen(prog->args[i])))
		{
			var->envc = tmp->next;
			tmp = var->envc;
		}
		i++;
	}
	save = tmp;
	var->envc = save;
	printf("%s\n", var->envc->line);
	//save = unset_inside(var->envc);
	var->status = 0;
}
