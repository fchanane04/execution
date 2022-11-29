/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:32:30 by nel-brig          #+#    #+#             */
/*   Updated: 2022/11/26 01:32:33 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"
#include "../minishell.h"

void	join(char *a, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		a[i] = s2[j];
		i++;
		j++;
	}
	a[i] = '\0';
	free(s1);
	s1 = NULL;
}

int	error_pipe(t_token *token)
{
	if (token->index == 0)
	{
		printf("bash: %s%s\'\n", ERROR_MSG, token->value);
		return (-1);
	}
	else if (token->next == NULL)
	{
		printf("bash: %s%s\'\n", ERROR_MSG, "newline");
		return (-1);
	}
	else if (token->next->type == PIPE)
	{
		printf("bash: %s%s\'\n", ERROR_MSG, token->value);
		return (-1);
	}
	return (0);
}

int	error(t_token *token)
{	
	int	type;

	if (!token->next)
	{
		printf("bash: %s%s\'\n", ERROR_MSG, "newline");
		return (-1);
	}
	type = token->next->type;
	if (type == PIPE || type == R_RED
		|| type == L_RED || type == APP || type == DEL)
	{
		printf("bash: %s%s\'\n", ERROR_MSG, token->value);
		return (-1);
	}
	return (0);
}

int	syntax(t_token *token)
{
	int	type;

	while (token != NULL)
	{
		type = token->type;
		if (type == PIPE)
		{
			if (error_pipe(token) == -1)
				return (-1);
		}
		else if (type == R_RED || type == L_RED || type == DEL || type == APP)
		{
			if (error(token) == -1)
				return (-1);
		}
		token = token->next;
	}
	return (0);
}
