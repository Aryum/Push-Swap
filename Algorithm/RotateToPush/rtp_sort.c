/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:17:17 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/26 13:30:22 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtp.h"

static void	swap(t_rtp *a, t_rtp *b)
{
	t_rtp	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	updatenegative(t_rtp *tab)
{
	int	i;

	i = 0;
	while (tab[i].type != none)
	{
		if (tab[i].cost < 0)
			tab[i].cost = -1 * tab[i].cost;
		i++;
	}
	return (i);
}

void	rtp_sort(t_rtp *tab)
{
	int	i;
	int	h;
	int	swapped;
	int	size;

	i = 0;
	h = 0;
	swapped = 0;
	size = updatenegative(tab);
	while (i < size)
	{
		while (h < size - i - 1)
		{
			if (tab[h].cost > tab[h + 1].cost)
			{
				swap(&tab[h], &tab[h + 1]);
				swapped = 1;
			}
			h++;
		}
		if (!swapped)
			break ;
		h = 0;
		i++;
	}
}
