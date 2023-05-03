/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:45:13 by madmax42          #+#    #+#             */
/*   Updated: 2023/05/02 09:45:34 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include "philo.h"

/* eating */

void	pick_up_forks(t_philo *philo);
void	update_meal_count(t_philo *philo);
void	release_forks(t_philo *philo);
void	eating(t_philo *philo);

/* routine */

void	*start_philo_routine(void *args);
void	routine_one_philo(t_philo *philo);
void	routine(t_philo *philo);

#endif