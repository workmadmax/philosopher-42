/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:44:02 by madmax42          #+#    #+#             */
/*   Updated: 2023/05/13 10:52:38 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->p_data->nb_philo == 1)
		routine_one_philo(philo);
	else
		routine(philo);
	return (NULL);
}

void	routine_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_state(philo, FORK);
	wait_for_time(philo->p_data, philo->p_data->time_to_die, philo);
	pthread_mutex_unlock(philo->right_fork);
	printf("(%ld) (%d) died\n",
		get_time_ms(philo->p_data), philo->id);
}

void	routine(t_philo *philo)
{
	while (!check_philo_alive(philo) && !check_meals_limit(philo))
	{
		eating(philo);
		if (!check_philo_alive(philo) && !check_meals_limit(philo))
			print_state(philo, SLEEPING);
		if (!check_philo_alive(philo) && !check_meals_limit(philo))
			wait_for_time(philo->p_data, philo->p_data->time_to_sleep, philo);
		if (!check_philo_alive(philo) && !check_meals_limit(philo))
			print_state(philo, THINKING);
	}
}
