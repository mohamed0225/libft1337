/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaidbe <mohaidbe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:15:40 by mohaidbe          #+#    #+#             */
/*   Updated: 2026/10/31 13:45:37 by mohaidbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (sign == 1 && num > (LONG_MAX - (*nptr - '0')) / 10)
			return (-1);
		if (sign == -1 && num > LONG_MAX / 10)
			return (0);
		if (sign == -1 && num == LONG_MAX / 10 && (*nptr - '0') > 8)
			return (0);
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(num * sign));
}
