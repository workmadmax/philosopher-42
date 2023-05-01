/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:15:38 by madmax42          #+#    #+#             */
/*   Updated: 2023/05/01 09:03:19 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philo_alive(t_philo *philo)
{
	pthrad_mutex_lock(&philo->p_mutex->has_dead);
	if (philo->p_data->dead)
	{
		pthread_mutex_unlock(&philo->p_mutex->has_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->p_data->dead);
	return (0);
}

int	check_meals_limit(t_philo *philo)
{
	pthread_mutex_lock(&philo->p_data->mutex.enough_meals);
	if (philo->nb_meals == philo->p_data->meals)
	{
		pthread_mutex_unlock(&philo->p_data->mutex.enough_meals);
		return (1);
	}
	pthread_mutex_unlock(&philo->p_data->mutex.enough_meals);
	return (0);
}

void	check_dead(t_philo *philo)
{
	int	idx;
	int	time;

	idx = 0;
	pthread_mutex_lock(&philo->p_data->mutex.print_state);
	while (idx < philo->p_data->nb_philo)
	{
		time = get_time_ms(philo->p_data);
		if (time > philo->p_data->time_to_die + \
			philo->p_data->philos[idx].last_meal
			&& !check_philo_alive(&philo->p_data->philos[idx])
			&& !check_meals_limit(&philo->p_data->philos[idx]))
		{
			pthread_mutex_lock(&philo->p_data->mutex.has_dead);
			philo->p_data->dead = 1;
			pthread_mutex_unlock(&philo->p_data->mutex.has_dead);
			printf("%ld %d died\n", time, get_time_ms(philo->p_data),
				philo->p_data->philos[idx].id);
		}
		pthread_mutex_unlock(&philo->p_data->mutex.print_state);
		return ;
		idx++;
	}
}
