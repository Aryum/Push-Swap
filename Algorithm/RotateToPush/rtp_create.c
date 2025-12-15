/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:40:27 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/26 13:29:38 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtp.h"

static int	counter(t_list *lst, int tar, int (*func)(int, int))
{
	int	ret;

	ret = 0;
	while (lst != NULL)
	{
		if (func(tar, lst->val.index))
			ret++;
		lst = lst->next;
	}
	return (ret);
}

void	rtp_updaterot(t_data data, t_rtp *rtp)
{
	t_stack	stack;
	t_func	func;

	stack = *get_stack(data, rtp->from);
	func = get_func(rtp->from);
	rtp->push = func.push;
	rtp->cost = mv_calculate_push(stack, rtp->tar_idx);
	if (rtp->cost >= 0)
	{
		rtp->rotate = func.rot;
		rtp->type = normal;
	}
	else
	{
		rtp->type = reverse;
		rtp->rotate = func.rev_rot;
	}
}

t_rtp	rtp_create(t_data data, t_id id, int tar_idx)
{
	t_rtp	ret;

	ret.from = id;
	ret.tar_idx = tar_idx;
	if (tar_idx != -1)
		rtp_updaterot(data, &ret);
	else
		ret.type = none;
	return (ret);
}

t_rtp	*rtp_create_all(t_data data, t_id push, int nbr, int (*func)(int, int))
{
	t_list	*lst;
	t_rtp	*ret;
	int		len;
	int		i;

	i = 0;
	lst = *get_lst_topush(data, push);
	len = counter(lst, nbr, func);
	ret = lib_calloc(sizeof(t_rtp), len + 1);
	if (ret != NULL)
	{
		while (lst != NULL)
		{
			if (func(nbr, lst->val.index))
			{
				ret[i] = rtp_create(data, push, lst->val.index);
				i++;
			}
			lst = lst->next;
		}
		ret[len] = rtp_create(data, push, -1);
		rtp_sort(ret);
	}
	return (ret);
}
