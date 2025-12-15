/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_h_indexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:13:44 by ricsanto          #+#    #+#             */
/*   Updated: 2025/07/08 15:25:32 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psr.h"

static void	swap_nbr(int *a, int *b)
{ 
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	sort_arr(int *tab, int size)
{
	int	i;
	int	h;
	int	swapped;

	i = 0;
	h = 0;
	swapped = 1;
	while (i < size)
	{
		while (h < size - i - 1)
		{
			if (tab[h] > tab[h + 1])
			{
				swap_nbr(&tab[h], &tab[h + 1]);
				swapped = 0;
			}
			h++;
		}
		if (swapped == 1)
			break ;
		h = 0;
		i++;
	}
}

static int	*get_arr(t_list *lst, int lst_sz)
{
	int	*ret;
	int	i;

	i = 0;
	ret = calloc(sizeof(int *), lst_sz);
	if (ret != NULL)
	{
		while (i < lst_sz)
		{
			ret[i] = lst->val.nbr;
			i++;
			lst = lst->next;
		}
		sort_arr(ret, lst_sz);
	}
	return (ret);
}

static void	iter(t_list *lst, int *arr, int sz)
{
	int	i;

	i = 0;
	while (i < sz)
	{
		if (arr[i] == lst->val.nbr)
			lst->val.index = i + 1;
		i++;
	}
}

void	psr_h_indexer(t_stack *stack)
{
	t_list	*lst;
	int		*arr;
	int		sz;

	lst = stack->lst;
	sz = lst_size(lst);
	arr = get_arr(lst, sz);
	stack->min = 1;
	stack->max = sz;
	if (arr == NULL)
	{
		print_f("Failed to index arr");
		return ;
	}
	while (lst != NULL)
	{
		iter(lst, arr, sz);
		lst = lst->next;
	}
	free(arr);
}
