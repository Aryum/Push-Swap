/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:37:16 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/09 18:08:35 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>

void	lib_bzero(void *s, size_t n);

void	*lib_calloc(size_t nmemb, size_t size);

void	*lib_memset(void *s, int c, size_t n);

char	**lib_split(char const *s, char c);

void	lib_split_clean(char **arr);

char	*lib_substr(char const *s, unsigned int start, size_t len);

size_t	lib_strlen(const char *s);

size_t	lib_strlcpy(char *dst, const char *src, size_t size);

char	*lib_strdup(const char *s);

#endif