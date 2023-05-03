/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:22:43 by madmax42          #+#    #+#             */
/*   Updated: 2023/05/01 09:24:10 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKERS_H
# define CHECKERS_H

# include "philo.h"

int			check_args_isdigit(char *args);
int			check_int_overflow(char *args);
int			check_positive_number(char *args);
int			check_input_validity(int argc, char **argv);

/* check routine */

int			check_philo_alive(t_philo *philo);
int			check_meals_limit(t_philo *philo);
void		check_dead(t_philo *philo);

#endif