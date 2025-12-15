/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:33:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/26 13:23:09 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include <stdlib.h>

typedef struct s_nbr
{
	int	nbr;
	int	index;
}	t_nbr;

typedef struct s_list
{
	t_nbr			val;
	struct s_list	*next;
	struct s_list	*last;
}	t_list;

t_list	*lst_new(t_nbr content);

t_list	*lst_map(t_list *lst, t_nbr (*f)(t_nbr));

t_list	*lst_last(t_list *lst);

void	lst_iter(t_list *lst, void (*f)(t_nbr *));

void	lst_delone(t_list **start, t_list *node);

void	lst_add_back(t_list **lst, t_nbr new);

void	lst_add_front(t_list **lst, t_nbr new);

void	lst_clear(t_list **lst);

int		lst_size(t_list *lst);

#endif