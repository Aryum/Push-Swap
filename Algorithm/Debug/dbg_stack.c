/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:24:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/26 13:24:29 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg.h"

static void	printcontent(t_list *lst)
{
	if (lst != NULL)
		print_f("%d", lst->val.index);
}

void	dbg_print_stack(t_data data)
{
	t_list	*a;
	t_list	*b;

	a = data.a->lst;
	b = data.b->lst;
	print_f("\n\nA	|	B\n");
	print_f("____________________________\n");
	while (a != NULL || b != NULL)
	{
		printcontent(a);
		print_f("	|	");
		printcontent(b);
		print_f("\n");
		if (a != NULL)
			a = a->next;
		if (b != NULL)
			b = b->next;
	}
	print_f("____________________________\n");
	print_f(" %d	|	%d	Total\n", data.a->size, data.b->size);
	print_f(" %d	|	%d	Max\n", data.a->max, data.b->max);
	print_f(" %d	|	%d	Min\n", data.a->min, data.b->min);
	print_f("____________________________\n\n");
}
