/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:57:32 by madmax42          #+#    #+#             */
/*   Updated: 2023/04/30 17:03:56 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_mutex
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_state;
	pthread_mutex_t	has_dead;
	pthread_mutex_t	enough_meals;
	pthread_mutex_t	thread_create;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_mutex;

typedef struct s_philo
{
	int				id;
	int				nb_meals;
	int				is_alive;
	int				is_eating;
	long			start_time;
	long			last_meal;
	struct s_data	*p_data;
	t_mutex			*p_mutex;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	int				dead;
	long			start_time;
	long			start_time_sec;
	long			start_time_usec;
	t_philo			*philos;
	t_mutex			mutex;
}	t_data;

#endif