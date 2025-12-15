/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_edges.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:10:53 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/19 15:16:45 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chk.h"

int	is_min_ontop(t_stack stack)
{
	return (stack.lst->val.index == stack.min);
}

int	is_max_ontop(t_stack stack)
{
	return (stack.lst->val.index == stack.max);
}

int	is_min_onbottom(t_stack stack)
{
	return (lst_last(stack.lst)->val.index == stack.min);
}

int	is_max_onbottom(t_stack stack)
{
	return (lst_last(stack.lst)->val.index == stack.max);
}
