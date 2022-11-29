/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:50:18 by fchanane          #+#    #+#             */
/*   Updated: 2022/11/29 21:42:46 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../minishell.h"

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	sig_child(int sig)
{
	if (sig == SIGQUIT)
	{
		printf("Quit %d\n", SIGQUIT);
		exit(0);
	}
}

void	signal_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		var->status = 1;
		exit(var->status);
	}
}
