/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:48:16 by fchanane          #+#    #+#             */
/*   Updated: 2022/11/29 21:38:21 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char)s1[i]) != ((unsigned char)s2[i]))
			return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
		if (!s1[i] || !s2[i])
			break ;
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char			*ptr;
	unsigned int	i;

	ptr = malloc (ft_strlen(s1) + 1);
	i = 0;
	if (ptr)
	{
		while (s1[i])
		{
			ptr[i] = (char)s1[i];
			i++;
		}
	ptr[i] = '\0';
	}
	return (ptr);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*sub;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub = malloc (sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
