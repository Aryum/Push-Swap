/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_two.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:22:36 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/26 13:52:22 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srt.h"

void	srt_two(t_data data, t_id id)
{
	t_stack	*stack;
	t_func	func;

	stack = get_stack(data, id);
	func = get_func(id);
	if (next_lower(stack->lst))
		func.swap(data);
}
