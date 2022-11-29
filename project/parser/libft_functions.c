/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:31:10 by nel-brig          #+#    #+#             */
/*   Updated: 2022/11/26 01:31:11 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"
#include "../minishell.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*get_char_as_string(char c)
{
	char	*s;

	s = NULL;
	s = malloc(sizeof(char) * 2);
	if (!s)
		exit(EXIT_FAILURE);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 != NULL)
		return (strdup(s2));
	else if (s1 == NULL)
		return (NULL);
	a = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (a == NULL)
		return (0);
	join(a, s1, s2);
	return (a);
}

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
