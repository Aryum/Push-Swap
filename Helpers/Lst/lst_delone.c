/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:04:09 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 12:14:30 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_delone(t_list **start, t_list *node)
{
	t_list	*current;

	if (start != NULL && *start != NULL && node != NULL)
	{
		current = node;
		if (*start == node)
			*start = (**start).next;
		if (current->last != NULL)
			current->last->next = current->next;
		else
			node = current->next;
		if (current->next != NULL)
			current->next->last = current->last;
		free (current);
	}
}
