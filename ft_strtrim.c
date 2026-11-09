/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaidbe <mohaidbe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:06:54 by mohaidbe          #+#    #+#             */
/*   Updated: 2026/11/02 10:01:19 by mohaidbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isset(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	slen;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	slen = ft_strlen(s1);
	while (s1[i] && ft_isset(s1[i], set) == 1)
		i++;
	j = slen - 1;
	while (j > i && ft_isset(s1[j--], set) == 1)
		slen--;
	slen -= i;
	p = malloc(slen + 1);
	if (!p)
		return (NULL);
	j = 0;
	while (slen-- > 0)
		p[j++] = s1[i++];
	p[j] = '\0';
	return (p);
}
