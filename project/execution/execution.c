/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:42:34 by fchanane          #+#    #+#             */
/*   Updated: 2022/11/29 21:58:50 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	ft_execute(t_parser *prog)
{
	int		typ;
	int		i;
	char	**save;

	if (!prog)
		return ;
	i = 0;
	typ = exec_type_check(prog);
	save = ft_heredoc(prog);
	if (var->hd_sig == -303)
		return ;
	if (typ == 0)
		exec_builtin(prog, save[0]);
	if (typ == 1)
		exec_single_cmd(prog, save[0]);
	if (typ == 2)
		exec_multi_cmd(prog, save);
}
