/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:15:22 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/12 14:10:23 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mv.h"

static int	swap_top(t_stack *stack, char c)
{
	t_list	*lst;
	t_nbr	temp;

	if (stack->lst == NULL || stack->lst->next == NULL)
		return (print_f("List %c is empty or just has 1 item"), 0);
	lst = stack->lst;
	temp = lst->val;
	lst->val = lst->next->val;
	lst->next->val = temp;
	mv_h_print("s", c);
	return (1);
}

void	mv_swap_a(t_data data)
{
	swap_top(data.a, 'a');
}

void	mv_swap_b(t_data data)
{
	swap_top(data.b, 'b');
}

void	mv_swap_both(t_data data)
{
	int	swap_a;
	int	swap_b;

	swap_a = swap_top(data.a, '\0');
	swap_b = swap_top(data.b, '\0');
	if (swap_a && swap_b)
		mv_h_print("s", 's');
	else
	{
		if (swap_a)
			mv_h_print("s", 'a');
		else
			mv_h_print("s", 'b');
		print_f("Swaping both when you shouldn't\n");
	}
}
