/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azha <ael-azha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:12:09 by ael-azha          #+#    #+#             */
/*   Updated: 2025/06/03 16:26:07 by ael-azha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "philo.h"
#include "utils.h"
#include "init.h"
#include "simulation.h"

int	check_args(char **av)
{
	if (number_only(av))
		return (1);
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
		return (1);
	if (ft_atoi(av[2]) < 60 || ft_atoi(av[2]) > MAX_INT)
		return (1);
	if (ft_atoi(av[3]) < 60 || ft_atoi(av[3]) > MAX_INT)
		return (1);
	if (ft_atoi(av[4]) < 60 || ft_atoi(av[4]) > MAX_INT)
		return (1);
	if (av[5] && (ft_atoi(av[5]) < 0 || ft_atoi(av[5]) > MAX_INT))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo		philos[PHILO_MAX_COUNT];
	t_mutex		forks[PHILO_MAX_COUNT];
	t_engine	engine;

	if (ac < 5 || ac > 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	else if (check_args(av))
	{
		printf("Error wrong argument\n");
		return (1);
	}
	init_engine(&engine, philos, forks);
	init_forks(&engine, forks, ft_atoi(av[1]));
	init_philos(&engine, philos, forks, av);
	launcher(&engine, philos[0].philo_count);
	destroy_all(&engine, NULL, philos[0].philo_count, 0);
	return (0);
}
