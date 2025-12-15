/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:35:01 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/19 12:15:01 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	stack_clear(t_stack *stack)
{
	if (stack != NULL)
	{
		if (stack->lst != NULL)
			lst_clear(&(stack->lst));
		free(stack);
	}
}

void	data_clear(t_data data)
{
	stack_clear(data.a);
	stack_clear(data.b);
}
