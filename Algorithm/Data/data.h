/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:11:47 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/26 13:46:02 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "../_Headers/alg.h"

void		stack_clear(t_stack *stack);

void		data_clear(t_data data);

t_data		data_ini(void);

t_stack		*get_stack(t_data stack, t_id id);

t_func		get_func(t_id id);

t_list		**get_lst_topush(t_data data, t_id pushto);

void		update_chunk(t_data *data, int min);

#endif