/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:43:17 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/26 18:11:49 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../../Helpers/Lst/lst.h"

typedef enum e_id
{
	a,
	b
}	t_id;

typedef enum e_dir
{
	normal,
	reverse,
	none
}	t_dir;

typedef struct s_stack
{
	t_list	*lst;
	t_id	id;
	int		size;
	int		max;
	int		min;
}	t_stack;

typedef struct s_chunk
{
	int		max;
	int		mid;
	int		min;
}	t_chunk;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	t_chunk	chunk;
	t_dir	next_rot;
	int		total_size;
	int		chunk_size;
}	t_data;

typedef struct s_func
{
	void	(*push)(t_data);
	void	(*rot)(t_data);
	void	(*rev_rot)(t_data);
	void	(*swap)(t_data);
}	t_func;

#endif