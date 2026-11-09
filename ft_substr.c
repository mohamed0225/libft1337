/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaidbe <mohaidbe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 08:48:44 by mohaidbe          #+#    #+#             */
/*   Updated: 2026/10/24 09:47:06 by mohaidbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	stlen;
	size_t	sublen;
	int		i;
	char	*p;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	stlen = ft_strlen(s);
	sublen = stlen - start;
	if (sublen > len)
		sublen = len;
	p = malloc(sublen + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (sublen-- > 0)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
