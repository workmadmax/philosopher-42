/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:47:42 by madmax42          #+#    #+#             */
/*   Updated: 2023/05/12 09:34:13 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_destroy(t_data *mutex)
{
	if (pthread_mutex_destroy(&mutex->has_dead))
		return (close_data(mutex));
	if (pthread_mutex_destroy(&mutex->enough_meals))
		return (close_data(mutex));
	if (pthread_mutex_destroy(&mutex->print_state))
		return (close_data(mutex));
	if (pthread_mutex_destroy(&mutex->thread_create))
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
