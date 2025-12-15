/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:35:16 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/16 12:59:38 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_iter(t_list *lst, void (*f)(t_nbr *))
{
	if (lst != NULL && f != NULL)
	{
		while (lst != NULL)
		{
			f(&((*lst).val));
			lst = (*lst).next;
		}
	}
}
