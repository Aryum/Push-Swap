/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:10:55 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 12:09:03 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

static void	clear(t_list **current)
{
	if ((**current).next != NULL)
		clear(&((**current).next));
	free (*current);
}

void	lst_clear(t_list **lst)
{
	if (lst != NULL && *lst != NULL)
	{
		clear(lst);
		*lst = NULL;
	}
}
