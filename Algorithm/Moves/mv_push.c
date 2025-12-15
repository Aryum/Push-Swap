/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:34:24 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/12 14:10:07 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mv.h"

static void	update_stack(t_stack *stk, t_nbr val)
{
	if (stk->size == 0)
	{
		stk->max = -1;
		stk->min = -1;
	}
	else if (val.index >= stk->max || val.index <= stk->min)
		mv_h_update(stk);
	else if (stk->max == -1 || stk->min == -1)
		mv_h_update(stk);
}

static void	push_first(t_stack *stk_add, t_stack *stk_take, char c)
{
	t_list	*node;

	if (stk_take->lst == NULL)
	{
		print_f("Trying to push from list %c that is empty\n", c);
		return ;
	}
	node = stk_take->lst;
	stk_take->lst = stk_take->lst->next;
	if (stk_take->lst != NULL)
		stk_take->lst->last = NULL;
	node->next = stk_add->lst;
	if (stk_add->lst != NULL)
		stk_add->lst->last = node;
	stk_add->lst = node;
	stk_add->size++;
	stk_take->size--;
	update_stack(stk_add, node->val);
	update_stack(stk_take, node->val);
	mv_h_print("p", c);
}

void	mv_pushfrom_b(t_data data)
{
	push_first(data.a, data.b, 'a');
	if (next_lower(data.a->lst))
		mv_swap_a(data);
}

void	mv_pushfrom_a(t_data data)
{
	push_first(data.b, data.a, 'b');
	if (is_uprchunk(data.chunk, data.b->lst->val.index))
	{
		if (data.next_rot == normal)
			mv_rotate_both(data);
		else
			mv_rotate_b(data);
	}
}
