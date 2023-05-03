/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:14:20 by madmax42          #+#    #+#             */
/*   Updated: 2023/05/03 16:42:50 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_params(t_data *data, char **argv)
{
	data->dead = 0;
	data->nb_philo = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		data->meals = ft_atol(argv[5]);
	else
		data->meals = -1;
	if (data->nb_philo > 200 || data->time_to_die < 60 || data->time_to_eat < 60
		|| data->time_to_sleep < 60)
	{
		error_msg("Error: bad arguments! \
			Can't have over 200philos or time under 60ms\n");
		return (1);
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->mutex.has_dead, NULL))
		return (error_msg("Error: mutex init failed\n"));
	if (pthread_mutex_init(&data->mutex.enough_meals, NULL))
		return (error_msg("Error: mutex init failed\n"));
	if (pthread_mutex_init(&data->mutex.print_state, NULL))
		return (error_msg("Error: mutex init failed\n"));
	if (pthread_mutex_init(&data->mutex.thread_create, NULL))
		return (error_msg("Error: mutex init failed\n"));
	return (0);
}

int	init_forks(t_data *data)
{
	int	idx;

	idx = -1;
	data->philos = ft_calloc(sizeof(t_philo), data->nb_philo);
	if (!data->philos)
		return (error_msg("Error: calloc failed\n"));
	data->mutex.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->nb_philo);
	if (!data->mutex.forks)
		return (error_msg("Error: malloc failed\n"));
	while (++idx < data->nb_philo)
	{
		if (pthread_mutex_init(&data->mutex.forks[idx], NULL))
			return (error_msg("Error: mutex init failed\n"));
	}
	idx = -1;
	while (++idx < data->nb_philo)
	{
		data->philos[idx].p_mutex->left_fork = &data->mutex.forks[idx];
		if (idx == data->nb_philo - 1)
			data->philos[idx].p_mutex->right_fork = &data->mutex.forks[0];
		else
			data->philos[idx].p_mutex->right_fork = &data->mutex.forks[idx + 1];
	}
	return (0);
}

int	init_time_stap(t_data *data)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (error_msg("Error: gettimeofday failed\n"));
	data->start_time_sec = time.tv_sec;
	data->start_time_usec = time.tv_usec;
	data->start_time = (data->start_time_sec * 1000)
		+ (data->start_time_usec / 1000);
	return (0);
}

int	create_thread(t_data *data, int idx)
{
	pthread_mutex_unlock(&data->mutex.thread_create);
	data->philos[idx].id = idx + 1;
	data->philos[idx].nb_meals = 0;
	data->philos[idx].p_data = data;
	pthread_mutex_lock(&data->mutex.has_dead);
	if (pthread_create(&data->philos[idx].thread,
			NULL, &start_philo_routine, &data->philos[idx]))
		return (error_msg("Error: thread create failed\n"));
	if (usleep(40) == -1)
		return (1);
	return (0);
}
