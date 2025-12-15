/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_selector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:25:13 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/26 13:48:57 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srt.h"

int	srt_selector(t_data *data)
{
	if (is_sorted(*data->a))
		return (1);
	else if (data->a->size == 2)
		return (srt_two(*data, a), 1);
	else if (data->a->size == 3)
		return (srt_three(*data, a), 1);
	else if (is_rev_sorted(*data->a))
		return (srt_rev(*data));
	else
		return (srt_rest(data));
}
