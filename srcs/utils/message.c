/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:50:39 by madmax42          #+#    #+#             */
/*   Updated: 2023/05/03 17:55:01 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_msg(char *msg)
{
	printf("%s", msg);
	return (1);
}

void	print_state(t_philo *philo, char *state)
{
	pthread_mutex_lock(&philo->p_data->print_state);
	if (!check_philo_alive(philo))
		printf("%ld %d %s\n", get_time_ms(philo->p_data), philo->id, state);
	pthread_mutex_unlock(&philo->p_data->print_state);
}
