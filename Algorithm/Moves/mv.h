/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:15:36 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/12 14:05:41 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MV_H
# define MV_H

# include "../_Headers/alg.h"

int		print_f(const char *string, ...);

void	mv_h_print(char *str, char c);

void	mv_h_update(t_stack *stack);

int		mv_calculate_push(t_stack stack, int tar_index);

//push
void	mv_pushfrom_b(t_data data);

void	mv_pushfrom_a(t_data data);

//rotate
void	mv_rotate_a(t_data data);

void	mv_rotate_b(t_data data);

void	mv_rotate_both(t_data data);

//rev rotate
void	mv_rotate_rev_a(t_data data);

void	mv_rotate_rev_b(t_data data);

void	mv_rotate_rev_both(t_data data);

//swap
void	mv_swap_a(t_data data);

void	mv_swap_b(t_data data);

void	mv_swap_both(t_data data);

#endif