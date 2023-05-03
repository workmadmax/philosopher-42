/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:47:42 by madmax42          #+#    #+#             */
/*   Updated: 2023/05/03 16:40:52 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_destroy(t_mutex *mutex)
{
	if (pthread_mutex_init(&mutex->print_state, NULL))
		return (1);
	if (pthread_mutex_init(&mutex->has_dead, NULL))
		return (1);
	if (pthread_mutex_init(&mutex->enough_meals, NULL))
		return (1);
	if (pthread_mutex_init(&mutex->thread_create, NULL))
		return (1);
	return (0);
}

int	clean_data(t_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->nb_philo)
	{
		if (pthread_join(data->philos[idx].thread, NULL))
			return (1);
		idx++;
	}
	mutex_destroy(&data->mutex);
	free(data->philos);
	free(data->mutex.forks);
	return (0);
}
