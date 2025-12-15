/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:20:07 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/16 12:59:38 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list	*lst_new(t_nbr content)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	if (ret != NULL)
	{
		(*ret).val = content;
		(*ret).next = NULL;
		(*ret).last = NULL;
	}
	return (ret);
}
