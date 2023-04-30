/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:21:55 by madmax42          #+#    #+#             */
/*   Updated: 2023/04/30 17:26:47 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

/* libft */

int			ft_isdigit(char c);
void		*ft_memset(void *string, int c, size_t n);
void		ft_bzero(void *dest, size_t n);
void		*ft_calloc(size_t count, size_t size);
long long	ft_atol(const char *str);

#endif