/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:47:42 by madmax42          #+#    #+#             */
/*   Updated: 2023/05/06 11:28:48 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_destroy(t_data *mutex)
{
	if (pthread_mutex_init(&mutex->has_dead, NULL))
		return (close_data(mutex));
	if (pthread_mutex_init(&mutex->enough_meals, NULL))
		return (close_data(mutex));
	if (pthread_mutex_init(&mutex->print_state, NULL))
		return (close_data(mutex));
	if (pthread_mutex_init(&mutex->thread_create, NULL))
		return (close_data(mutex));
	return (0);
}

int	close_data(t_data *data)
{
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
	return (1);
}

int	clean_data(t_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->nb_philo)
	{
		if (pthread_join(data->philos[idx].thread, NULL))
			return (1);
		++idx;
	}
	mutex_destroy(data);
	free(data->philos);
	free(data->forks);
	return (0);
}
