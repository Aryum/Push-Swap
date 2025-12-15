/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:39:01 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/16 12:59:38 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list	*lst_map(t_list *lst, t_nbr (*f)(t_nbr))
{
	t_list	*ret;
	t_nbr	cur_content;

	if (lst == NULL || f == NULL)
		return (NULL);
	ret = NULL;
	while (lst != NULL)
	{
		cur_content = f((*lst).val);
		lst_add_back(&ret, cur_content);
		lst = ((*lst).next);
	}
	return (ret);
}
