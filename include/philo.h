/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:46:13 by madmax42          #+#    #+#             */
/*   Updated: 2023/05/03 18:31:26 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# include "defines.h"

/* structs */

typedef struct s_philo
{
	int				id;
	int				nb_meals;
	long			last_meal;
	pthread_t		thread;
	struct s_data	*p_data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	int				dead;
	long			start_time;
	long			start_time_sec;
	long			start_time_usec;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	has_dead;
	pthread_mutex_t	enough_meals;
	pthread_mutex_t	print_state;
	pthread_mutex_t	thread_create;
}	t_data;

/* checkers */

int			check_args_isdigit(char *args);
int			check_int_overflow(char *args);
int			check_positive_number(char *args);
int			check_input_validity(int argc, char **argv);

/* check routine */

int			check_philo_alive(t_philo *philo);
int			check_meals_limit(t_philo *philo);
void		check_dead(t_data *data);

/* eating */

void		pick_up_forks(t_philo *philo);
void		update_meal_count(t_philo *philo);
void		release_forks(t_philo *philo);
void		eating(t_philo *philo);

/* routine */

void		*start_philo_routine(void *args);
void		routine_one_philo(t_philo *philo);
void		routine(t_philo *philo);

/* clean data */

int			mutex_destroy(t_data *mutex);
int			clean_data(t_data *data);
int			close_data(t_data *data);

/* init data */

int			init_params(t_data *data, char **argv);
int			init_mutex(t_data *data);
int			init_forks(t_data *data);
int			init_time_stap(t_data *data);
int			create_thread(t_data *data, int idx);

/* libft */

int			ft_isdigit(char c);
void		*ft_memset(void *string, int c, size_t n);
void		ft_bzero(void *dest, size_t n);
void		*ft_calloc(size_t count, size_t size);
long long	ft_atol(const char *str);

/* messages */

int			error_msg(char *msg);
void		print_state(t_philo *philo, char *state);

/* time stap */

long		get_time_ms(t_data *time);
int			wait_for_time(t_data *data, int time_to_wait, t_philo *philo);

#endif