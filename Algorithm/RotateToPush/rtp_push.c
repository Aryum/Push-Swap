/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:45:41 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/26 18:14:55 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtp.h"

static void	rec(t_data data, t_list **lst, t_rtp rot)
{
	if ((*lst)->val.index == rot.tar_idx)
		rot.push(data);
	else
	{
		rot.rotate(data);
		rec(data, lst, rot);
	}
}

static void	update(t_data data, t_rtp *rots)
{
	int	i;

	i = 0;
	if (rots[i].tar_idx != -1)
	{
		while (rots[i].tar_idx != -1)
		{
			rtp_updaterot(data, &rots[i]);
			i++;
		}
		rtp_sort(rots);
	}
}

void	rtp_push_single(t_data data, t_rtp rot)
{
	rec (data, get_lst_topush(data, rot.from), rot);
}

int	rtp_push_multiple(t_data data, t_id id, int nbr, int (*func)(int, int))
{
	t_rtp	*rots;

	rots = rtp_create_all(data, id, nbr, func);
	if (rots != NULL)
	{
		rtp_push_arr(data, rots);
		free(rots);
		return (1);
	}
	return (0);
}

void	rtp_push_arr(t_data data, t_rtp *rots)
{
	int	i;

	i = 0;
	while (rots[i].type != none)
	{
		data.next_rot = rots[i + 1].type;
		rtp_push_single(data, rots[i]);
		update(data, &(rots[i + 1]));
		i++;
	}
}
