/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:31:52 by nel-brig          #+#    #+#             */
/*   Updated: 2022/11/26 01:31:53 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"
#include "../minishell.h"

void print_tokens(t_token *token)
{
	if (token == NULL)
	{
		printf("token == NULL\n");
		return;
	}
    else if (token->value == NULL)
	{
        printf("token value == NULL\n");
		return;
	}
    while (token != NULL)
    {
        printf("token == (%d,|%s|,%d, %d)\n", token->type, token->value, token->index, token->expand);
        token = token->next;
    }

}

void	print_tab(t_token **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		printf("tab number %d\n", i);
		print_tokens(tab[i]);
		i++;
		printf("=========\n");
	}
}

void	print_data(char **s, char *str)
{
	int	i;

	i = 0;
	if (s == NULL)
		printf("         NULL\n");
	while (s != NULL && s[i] != NULL)
		printf("%s == |%s|\n", str, s[i++]);
}

void	print_files(t_files *files)
{
	while (files != NULL)
	{
		printf("filename == %s, type == %d\n", files->filename, files->type);
		files = files->next;
	}
}

void	print_struct(t_parser *cmd_table)
{
	int	i;

	i = 0;
	while (cmd_table != NULL)
	{
		printf("\033[1;35m--------args-----------\n\n");
		print_data(cmd_table->args, "args");
		printf("\033[1;35m--------files-------\n\n");
		print_files(cmd_table->files);
		printf("\033[1;37m=<>=<>=<>=<>=<>=<>=<>=<>=<>=<>=next=<>=<>=<>=<>=<>=<>=<>=<>=<>=<>=\n\n");
		cmd_table = cmd_table->next;
	}
}
