/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:11:56 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/26 13:47:18 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

t_list	**get_lst_topush(t_data data, t_id pushfrom)
{
	if (pushfrom == a)
		return (&(data.a->lst));
	if (pushfrom == b)
		return (&(data.b->lst));
	return (NULL);
}

t_stack	*get_stack(t_data stack, t_id id)
{
	if (id == a)
		return (stack.a);
	else
		return (stack.b);
}

t_func	get_func(t_id id)
{
	t_func	ret;

	if (id == a)
	{
		ret.push = mv_pushfrom_a;
		ret.rot = mv_rotate_a;
		ret.rev_rot = mv_rotate_rev_a;
		ret.swap = mv_swap_a;
	}
	else
	{
		ret.push = mv_pushfrom_b;
		ret.rot = mv_rotate_b;
		ret.rev_rot = mv_rotate_rev_b;
		ret.swap = mv_swap_b;
	}
	return (ret);
}
