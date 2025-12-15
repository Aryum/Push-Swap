/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_chunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:17:57 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/25 15:50:37 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chk.h"

int	is_uprchunk(t_chunk chunk, int i)
{
	if (chunk.min == -1)
		return (0);
	return (i > chunk.mid && i <= chunk.max);
}
