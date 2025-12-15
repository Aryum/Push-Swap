/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rotate_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:20:09 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/12 14:10:11 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mv.h"

static int	rev_rotate(t_stack *stack, char c)
{
	t_list	*lst_tmp;
	t_nbr	nbr_tmp;

	if (stack->lst == NULL)
	{
		print_f("Trying to rotate list %c that is empty\n", c);
		return (0);
	}
	lst_tmp = lst_last(stack->lst);
	nbr_tmp = lst_tmp->val;
	while (lst_tmp->last != NULL)
	{
		lst_tmp->val = lst_tmp->last->val;
		lst_tmp = lst_tmp->last;
	}
	lst_tmp->val = nbr_tmp;
	mv_h_print("rr", c);
	return (1);
}

void	mv_rotate_rev_a(t_data data)
{
	rev_rotate(data.a, 'a');
}

void	mv_rotate_rev_b(t_data data)
{
	rev_rotate(data.b, 'b');
}

void	mv_rotate_rev_both(t_data data)
{
	int	rot_a;
	int	rot_b;

	rot_a = rev_rotate(data.a, '\0');
	rot_b = rev_rotate(data.b, '\0');
	if (rot_a && rot_b)
		mv_h_print("rr", 'r');
	else
	{
		if (rot_a)
			mv_h_print("rr", 'a');
		else
			mv_h_print("rr", 'b');
		print_f("Rotating both when you shouldn't\n");
	}
}
