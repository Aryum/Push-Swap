/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_agrs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:35:36 by ricsanto          #+#    #+#             */
/*   Updated: 2025/07/11 11:48:35 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psr.h"

static int	get_nbrs(t_stack *stack, char *c)
{
	int		i;
	char	**arr;
	long	cur;

	i = 0;
	arr = lib_split(c, ' ');
	if (arr[i] == 0)
		return (lib_split_clean(arr), 0);
	while (arr[i] != NULL)
	{
		cur = 0;
		if (lib_strlen(arr[i]) < 12 && psr_h_try_get_number(arr[i], &cur))
		{
			if (!psr_h_try_add_number(stack, (int)cur))
				return (lib_split_clean(arr), 0);
		}
		else
			return (lib_split_clean(arr), 0);
		i++;
	}
	return (lib_split_clean(arr), 1);
}

int	psr_agrs(t_data *data, int argc, char **argv)
{
	int	arg_i;

	if (argc == 1 || data == NULL)
		return (0);
	arg_i = 1;
	while (arg_i < argc)
	{
		if (!get_nbrs(data->a, argv[arg_i]))
		{
			lst_clear(&(data->a->lst));
			return (0);
		}
		arg_i++;
	}
	psr_h_indexer(data->a);
	data->total_size = data->a->size;
	return (1);
}
