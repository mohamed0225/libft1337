/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaidbe <mohaidbe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:20:34 by mohaidbe          #+#    #+#             */
/*   Updated: 2026/10/27 10:59:45 by mohaidbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*t;

	t = NULL;
	while (*s)
	{
		if (*(unsigned char *) s == (unsigned char) c)
			t = s;
		s++;
	}
	if (*(unsigned char *) s == (unsigned char) c)
		return ((char *) s);
	return ((char *)t);
}
