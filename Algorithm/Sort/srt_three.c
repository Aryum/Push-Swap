/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:22:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/26 13:51:56 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srt.h"

static int	rev_sort(t_data data, t_stack *stack, t_func func)
{
	if (is_rev_sorted(*stack))
	{
		func.swap(data);
		func.rev_rot(data);
		return (1);
	}
	return (0);
}

static int	top(t_data data, t_stack *stack, t_func func)
{
	t_nbr	nbr;

	nbr = stack->lst->val;
	if (nbr.index == stack->min)
	{
		func.swap(data);
		func.rot(data);
		return (1);
	}
	else if (nbr.index == stack->max)
	{
		func.rot(data);
		return (1);
	}
	return (0);
}

static void	bottom(t_data data, t_stack *stack, t_func func)
{
	t_nbr	nbr;

	nbr = lst_last(stack->lst)->val;
	if (nbr.index == stack->min)
		func.rev_rot(data);
	else if (nbr.index == stack->max)
		func.swap(data);
}

void	srt_three(t_data data, t_id id)
{
	t_stack	*stack;
	t_func	func;

	stack = get_stack(data, id);
	func = get_func(id);
	if (is_sorted(*stack))
		return ;
	if (!rev_sort(data, stack, func))
	{
		if (!top(data, stack, func))
			bottom(data, stack, func);
	}
}
