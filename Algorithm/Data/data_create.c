/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:13:58 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/26 13:39:48 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static t_stack	*ini_stack(t_id id)
{
	t_stack	*ret;

	ret = malloc(sizeof(t_stack));
	if (ret != NULL)
	{
		ret->lst = NULL;
		ret->size = 0;
		ret->id = id;
		ret->max = -1;
		ret->min = -1;
	}
	return (ret);
}

t_data	data_ini(void)
{
	t_data	ret;

	ret.a = ini_stack(a);
	ret.b = ini_stack(b);
	if (ret.a == NULL || ret.b == NULL)
		data_clear(ret);
	ret.chunk_size = 0;
	ret.total_size = 0;
	ret.chunk.max = -1;
	ret.chunk.mid = -1;
	ret.chunk.min = -1;
	return (ret);
}

void	update_chunk(t_data *data, int min)
{
	t_chunk	chunk;

	chunk.max = min + (data->chunk_size * 2);
	if (chunk.max >= data->total_size - 3)
		chunk.max = data->total_size - 3;
	chunk.mid = chunk.max - data->chunk_size;
	chunk.min = chunk.mid - data->chunk_size;
	data->chunk = chunk;
}
