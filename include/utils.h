/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:21:55 by madmax42          #+#    #+#             */
/*   Updated: 2023/05/03 16:45:48 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

/* clean data */

int			mutex_destroy(t_mutex *mutex);
int			clean_data(t_data *data);

/* init data */

int			init_params(t_data *data, char **argv);
int			init_mutex(t_data *data);
int			init_forks(t_data *data);
int			init_time_stap(t_data *data);
int			create_thread(t_data *data, int idx);

/* libft */

int			ft_isdigit(char c);
void		*ft_memset(void *string, int c, size_t n);
void		ft_bzero(void *dest, size_t n);
void		*ft_calloc(size_t count, size_t size);
long long	ft_atol(const char *str);

/* messages */

int			error_msg(char *msg);
void		print_state(t_philo *philo, char *state);

/* time stap */

long		get_time_ms(t_data *time);
int			wait_for_time(t_data *data, int time_to_wait, t_philo *philo);


#endif