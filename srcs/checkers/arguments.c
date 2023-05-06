/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:30:27 by madmax42          #+#    #+#             */
/*   Updated: 2023/05/03 18:17:32 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args_isdigit(char *args)
{
	int	idx;

	idx = 0;
	if (args[idx] == '+' || args[idx] == '-')
		idx++;
	if (!args[idx])
		return (1);
	while (args[idx])
	{
		if (!ft_isdigit(args[idx]))
			return (1);
		idx++;
	}
	return (0);
}

int	check_int_overflow(char *args)
{
	int	size;

	size = 0;
	while (args[size])
		size++;
	if (size > 11)
		return (1);
	if (size == 11 && ft_atol(args) > INT_MIN)
		return (1);
	if (size == 10 && ft_atol(args) > INT_MAX)
		return (1);
	return (0);
}

int	check_positive_number(char *args)
{
	if (ft_atol(args) <= 0)
		return (1);
	return (0);
}

int	check_input_validity(int argc, char **argv)
{
	int	idx;

	idx = 1;
	if (argc < 5 || argc > 6)
		return (error_msg("Error: bad arguments!\n"));
	while (argv[idx])
	{
		if (check_args_isdigit(argv[idx]))
			return (error_msg("Error: arguments only digits!\n"));
		if (check_int_overflow(argv[idx]))
			return (error_msg("Error: arguments overflow!\n"));
		if (check_positive_number(argv[idx]))
			return (error_msg("Error: arguments must be positive!\n"));
		++idx;
	}
	return (0);
}
