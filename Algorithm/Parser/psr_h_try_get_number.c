/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_h_try_get_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:57:12 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/12 14:10:45 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psr.h"

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	is_int(long i)
{
	if (i >= -2147483648 && i <= 2147483647)
		return (1);
	else
		return (0);
}

int	psr_h_try_get_number(char *c, long *nbr)
{
	int	i;
	int	signal;

	i = 0;
	signal = 1;
	if (c[i] == '-' && is_digit(c[i + 1]))
	{
		signal = -1;
		i++;
	}
	while (c[i] != '\0')
	{
		if (is_digit(c[i]) && is_int(*nbr))
		{
			*nbr = *nbr * (*nbr != 0) * 10 + c[i] - '0';
			if (!is_int(*nbr * signal))
				return (0);
		}
		else
			return (0);
		i++;
	}
	*nbr *= signal;
	return (1);
}
