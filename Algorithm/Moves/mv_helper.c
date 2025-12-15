/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:48:30 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/12 14:10:02 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mv.h"

void	mv_h_print(char *str, char c)
{
	if (c != '\0')
		print_f("%s%c\n", str, c);
}

void	mv_h_update(t_stack *stack)
{
	t_list	*lst;

	lst = stack->lst;
	stack->min = -1;
	stack->max = -1;
	while (lst != NULL)
	{
		if (stack->min == -1 || lst->val.index < stack->min)
			stack->min = lst->val.index;
		if (stack->max == -1 || lst->val.index > stack->max)
			stack->max = lst->val.index;
		lst = lst->next;
	}
}
