/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:09:17 by madmax42          #+#    #+#             */
/*   Updated: 2023/05/13 10:51:12 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_ms(t_data *time)
{
	struct timeval	tv;
	long			time_stap;

	if (gettimeofday(&tv, NULL) != 0)
		return (close_data(time));
	time_stap = (tv.tv_sec - time->start_time_sec) * 1000 + \
		(tv.tv_usec - time->start_time_usec) / 1000;
	return (time_stap);
}

int	wait_for_time(t_data *data, int time_to_wait, t_philo *philo)
{
	long	time;
	long	start_time;

	time = get_time_ms(data);
	start_time = get_time_ms(data);
	while (time < (time_to_wait + start_time) && !check_philo_alive(philo))
	{
		if (usleep(200) == -1)
			return (close_data(data));
		time = get_time_ms(data);
	}
	return (0);
}
