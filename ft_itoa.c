/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaidbe <mohaidbe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:53:47 by mohaidbe          #+#    #+#             */
/*   Updated: 2026/11/02 09:42:24 by mohaidbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_numlen(long n)
{
	int	l;

	l = 1;
	if (n < 0)
	{
		n = -n;
		l++;
	}
	while (n >= 10)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*p;

	num = n;
	len = ft_numlen(num);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	if (num < 0)
		num = -num;
	p[len] = '\0';
	--len;
	while (len >= 0)
	{
		p[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	if (n < 0)
		p[0] = '-';
	return (p);
}
