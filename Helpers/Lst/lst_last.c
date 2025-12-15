/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:56:31 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/04 17:15:40 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list	*lst_last(t_list *lst)
{
	if (lst != NULL)
	{
		while ((*lst).next != NULL)
			lst = (*lst).next;
	}
	return (lst);
}
