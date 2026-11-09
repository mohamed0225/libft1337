/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaidbe <mohaidbe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:43:02 by mohaidbe          #+#    #+#             */
/*   Updated: 2026/10/25 09:35:12 by mohaidbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *) big);
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j])
		{
			if (little [j + 1] == '\0' && i + j + 1 <= len)
				return ((char *) &big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
