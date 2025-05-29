/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:58:47 by dapetros          #+#    #+#             */
/*   Updated: 2025/05/29 16:22:30 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "philo.h"
#include "utils.h"
#include "init.h"
#include "simulation.h"

void	check_args(int ac, char **av)
{
	int		i;
	long	num;

	i = 0;
	if (ac < 5 || ac > 6)
		error_message("[Argument Count ERROR]\n", 1);
	while (++i < ac)
	{
		if (ft_isdigit_str(av[i]))
		{
			num = ft_atoi(av[i]);
			if (i == 1 && (num < 1 || num > PHILO_MAX_COUNT))
				error_message("[Argument ERROR]\n", 1);
			else if (i == 5 && (num < 0 || num > INT_MAX))
				error_message("[Argument ERROR]\n", 1);
			else if (i != 1 && i != 5 && (num < 1 || num > INT_MAX))
				error_message("[Argument ERROR]\n", 1);
		}
		else
			error_message("[Argument ERROR]\n", 1);
	}
}

int	main(int ac, char **av)
{
	t_philo		philos[PHILO_MAX_COUNT];
	t_mutex		forks[PHILO_MAX_COUNT];
	t_engine	engine;

	check_args(ac, av);
	init_engine(&engine, philos, forks);
	init_forks(&engine, forks, ft_atoi(av[1]));
	init_philos(&engine, philos, forks, av);
	launcher(&engine, philos[0].philo_count);
	destroy_all(&engine, NULL, philos[0].philo_count, 0);
	return (0);
}
