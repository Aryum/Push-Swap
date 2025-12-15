/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:23:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/26 13:24:39 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBG_H
# define DBG_H

# include "../_Headers/alg.h"

int		print_f(const char *string, ...);

void	dbg_print_stack(t_data data);

#endif