/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:55:58 by madmax42          #+#    #+#             */
/*   Updated: 2023/05/02 09:03:21 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int			idx;
	t_data		data;

	if (check_input_validity(argc, argv) || init_params(&data, argc, argv)
		|| init_mutex(&data) || init_forks(&data) || init_time_stap(&data))
		return (1);
	idx = 0;
	while (idx < data.nb_philo)
	{
		pthread_mutex_lock(&data.mutex.thread_create);
		if (createthread(&data, idx))
			return (1);
		idx += 2;
		if (idx > data.nb_philo && idx % 2 == 0)
			idx = 1;
		pthread_mutex_unlock(&data.mutex.thread_create);
	}
	while (!check_philo_alive(&data) && !check_meals(&data.philos)
		&& data.nb_philo > 1)
		check_dead(&data);
	clean_data(&data);
	return (0);
}
