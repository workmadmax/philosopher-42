/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:08:42 by madmax42          #+#    #+#             */
/*   Updated: 2023/05/01 09:44:48 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up_forks(t_philo *philo)
{
	if (!check_philo_alive(philo))
	{
		if (philo->id == philo->p_data->nb_philo)
		{
			pthread_mutex_lock(philo->p_mutex->right_fork);
			print_state(philo, FORK);
			pthread_mutex_lock(philo->p_mutex->left_fork);
			print_state(philo, FORK);
		}
		else
		{
			pthread_mutex_lock(philo->p_mutex->left_fork);
			print_state(philo, FORK);
			pthread_mutex_lock(philo->p_mutex->right_fork);
			print_state(philo, FORK);
		}
	}
}

void	update_meal_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->p_mutex->enough_meals);
	if (philo->p_data->meals != -1)
		++philo->nb_meals;
	philo->last_meal = get_time_ms(philo->p_data);
	pthread_mutex_unlock(&philo->p_mutex->enough_meals);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->p_mutex->right_fork);
	pthread_mutex_unlock(philo->p_mutex->left_fork);
}

void	eating(t_philo *philo)
{
	pick_up_forks(philo);
	if (!check_philo_alive(philo))
	{
		pthread_mutex_lock(&philo->p_mutex->print_state);
		update_meal_count(philo);
		printf("%ld %d EATING\n", get_time_ms(philo->p_data), philo->id);
	}
	release_forks(philo);
}
