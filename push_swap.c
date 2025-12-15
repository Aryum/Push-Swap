/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:15:08 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/26 18:21:43 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(void)
{
	write(2, "Error\n", 6);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data = data_ini();
	if (psr_agrs(&data, argc, argv))
	{
		if (!srt_selector(&data))
			print_error();
		if (!is_sorted(*data.a))
			dbg_print_stack(data);
	}
	else
		print_error();
	data_clear(data);
}
