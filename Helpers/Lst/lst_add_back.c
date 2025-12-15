/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:30:04 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/18 15:03:11 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_add_back(t_list **lst, t_nbr new)
{
	t_list	*new_node;
	t_list	*last_node;

	if (lst == NULL)
		return ;
	new_node = lst_new(new);
	if (new_node == NULL)
		lst_clear(lst);
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		last_node = lst_last(*lst);
		(*last_node).next = new_node;
		(*new_node).last = last_node;
	}
}
