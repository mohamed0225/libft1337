/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaidbe <mohaidbe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 08:10:00 by mohaidbe          #+#    #+#             */
/*   Updated: 2026/10/25 11:26:59 by mohaidbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_lenword(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

static	char	*ft_pword(char const *s, char *p, int i, char c)
{
	int	j;

	j = 0;
	p = malloc((ft_lenword(s, c, i) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (s[i] != c && s[i])
	{
		p[j] = s[i];
		i++;
		j++;
	}
	p[j] = '\0';
	return (p);
}

static	int	ft_nword(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

static	char	**ft_freep(char **p, int j)
{
	while (j >= 0)
		free(p[j--]);
	free(p);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**p;

	i = 0;
	j = 0;
	p = malloc((ft_nword(s, c) + 1) * sizeof(char *));
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			p[j] = ft_pword(s, p[j], i, c);
		if (!p)
			return (ft_freep(p, j));
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	p[j] = NULL;
	return (p);
}
