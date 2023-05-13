/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:15:38 by madmax42          #+#    #+#             */
/*   Updated: 2023/05/13 10:52:10 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->p_data->has_dead);
	if (philo->p_data->dead)
	{
		pthread_mutex_unlock(&philo->p_data->has_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->p_data->has_dead);
	return (0);
}

int	check_meals_limit(t_philo *philo)
{
	pthread_mutex_lock(&philo->p_data->enough_meals);
	if (philo->nb_meals == philo->p_data->meals)
	{
		pthread_mutex_unlock(&philo->p_data->enough_meals);
		return (1);
	}
	pthread_mutex_unlock(&philo->p_data->enough_meals);
	return (0);
}

void	check_dead(t_data *data)
{
	int			idx;
	long		time;

	idx = 0;
	pthread_mutex_lock(&data->print_state);
	while (idx < data->nb_philo)
	{
		time = get_time_ms(data);
		if (time > data->time_to_die + data->philos[idx].last_meal
			&& !check_philo_alive(&data->philos[idx])
			&& !check_meals_limit(&data->philos[idx]))
		{
			pthread_mutex_lock(&data->has_dead);
			data->dead = 1;
			pthread_mutex_unlock(&data->has_dead);
			printf("(%ld) (%d) died\n",
				get_time_ms(data), data->philos[idx].id);
		}
		pthread_mutex_unlock(&data->print_state);
		return ;
		++idx;
	}
}
