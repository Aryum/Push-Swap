/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:24:15 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/12 14:10:17 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mv.h"

static int	rotate(t_stack *stack, char c)
{
	t_list	*lst_tmp;
	t_nbr	nbr_tmp;

	if (stack->lst == NULL)
		return (0);
	lst_tmp = stack->lst;
	nbr_tmp = stack->lst->val;
	while (lst_tmp->next != NULL)
	{
		lst_tmp->val = lst_tmp->next->val;
		lst_tmp = lst_tmp->next;
	}
	lst_tmp->val = nbr_tmp;
	mv_h_print("r", c);
	return (1);
}

void	mv_rotate_a(t_data data)
{
	rotate(data.a, 'a');
}

void	mv_rotate_b(t_data data)
{
	rotate(data.b, 'b');
}

void	mv_rotate_both(t_data data)
{
	int	rot_a;
	int	rot_b;

	rot_a = rotate(data.a, '\0');
	rot_b = rotate(data.b, '\0');
	if (rot_a && rot_b)
		mv_h_print("r", 'r');
	else
	{
		if (rot_a)
			mv_h_print("r", 'a');
		else
			mv_h_print("r", 'b');
		print_f("Rotating both when you shouldn't\n");
	}
}
