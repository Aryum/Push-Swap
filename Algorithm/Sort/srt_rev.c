/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:33:40 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/26 18:11:24 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srt.h"

int	srt_rev(t_data data)
{
	while (data.a->size > 3)
		mv_pushfrom_a(data);
	srt_three(data, a);
	while (data.b->size > 0)
	{
		mv_rotate_rev_b(data);
		mv_pushfrom_b(data);
	}
	while (data.a->min != data.a->lst->val.index)
		mv_rotate_rev_a(data);
	return (1);
}
