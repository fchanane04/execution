/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:31:08 by nel-brig          #+#    #+#             */
/*   Updated: 2022/11/25 16:31:10 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../minishell.h"

static char	*ft_strndup(char *s, size_t n)
{
	char	*a;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	a = (char *)malloc((n + 1) * sizeof(char));
	if (!a)
		return (0);
	while (i < n)
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

static size_t	ft_count(char *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c)
			word++;
	}
	return (word);
}

static char	**ft_loop(char *s, char c, size_t words)
{
	size_t	i;
	size_t	k;
	size_t	start;
	char	**a;

	i = 0;
	k = 0;
	a = (char **)malloc((words + 1) * sizeof(char *));
	if (!a)
		return (0);
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			if (k < words)
				a[k++] = ft_strndup((char *)&s[start], i - start);
		}
		else
			i++;
	}
	a[k] = NULL;
	return (a);
}

char	**ft_split(char *s, char c)
{
	char	**a;
	size_t	i;
	size_t	words;

	i = 0;
	if (!s)
		return (0);
	words = ft_count((char *)s, c);
	a = ft_loop((char *)s, c, words);
	return (a);
}
