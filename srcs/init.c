/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azha <ael-azha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:12:05 by ael-azha          #+#    #+#             */
/*   Updated: 2025/05/31 16:12:07 by ael-azha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_philos(t_engine *en, t_philo *philos, t_mutex *forks, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].times.die = ft_atoi(av[2]);
		philos[i].times.eat = ft_atoi(av[3]);
		philos[i].times.sleep = ft_atoi(av[4]);
		philos[i].times.last_meal = get_current_time();
		philos[i].times.born_time = get_current_time();
		philos[i].must_eat = -1;
		if (av[5])
			philos[i].must_eat = ft_atoi(av[5]);
		philos[i].meals_eaten = 0;
		philos[i].philo_count = ft_atoi(av[1]);
		philos[i].mutexes.left_fork = &forks[i];
		if (i == 0)
			philos[i].mutexes.right_fork = &forks[philos[i].philo_count - 1];
		else
			philos[i].mutexes.right_fork = &forks[i - 1];
		philos[i].mutexes.write_lock = &en->write_lock;
		philos[i].mutexes.meal_lock = &en->meal_lock;
		i++;
	}
}

void	init_forks(t_engine *engine, t_mutex *forks, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			destroy_all(engine, "[Mutex Init ERROR]\n", i, 1);
		i++;
	}
}

void	init_engine(t_engine *engine, t_philo *philos, t_mutex *forks)
{
	engine->forks = forks;
	engine->philos = philos;
	if (pthread_mutex_init(&engine->write_lock, NULL) != 0
		|| pthread_mutex_init(&engine->meal_lock, NULL) != 0)
		destroy_all(engine, "[Mutex Init ERROR]\n", -1, 1);
}
