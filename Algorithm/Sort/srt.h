/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:12:57 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/26 12:45:27 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRT_H
# define SRT_H

# include "../_Headers/alg.h"

int		srt_rest(t_data *data);

int		srt_rev(t_data data);

int		srt_selector(t_data *data);

void	srt_three(t_data data, t_id id);

void	srt_two(t_data data, t_id id);

#endif