/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azha <ael-azha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:06:50 by ael-azha          #+#    #+#             */
/*   Updated: 2025/06/03 17:29:04 by ael-azha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_all_eat(t_philo *philos)
{
	int		finished;
	int		i;

	i = 0;
	finished = 0;
	if (philos[0].must_eat == -1)
		return (0);
	while (i < philos[0].philo_count)
	{
		pthread_mutex_lock(philos->mutexes.meal_lock);
		if (philos[i].meals_eaten >= philos[i].must_eat)
			++finished;
		pthread_mutex_unlock(philos->mutexes.meal_lock);
		i++;
	}
	if (finished == philos[0].philo_count)
	{
		pthread_mutex_lock(philos->mutexes.write_lock);
		return (1);
	}
	return (0);
}

void	*obsorver(void *ptr)//monitor
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ptr;
	while (1)
	{
		i = 0;
		while (i < philos[0].philo_count)
		{
			pthread_mutex_lock(philos->mutexes.meal_lock);
			if (get_current_time() - philos[i].times.last_meal
				> philos[i].times.die)
			{
				pthread_mutex_unlock(philos->mutexes.meal_lock);
				print_action(&philos[i], RED" died"RESET);
				pthread_mutex_lock(philos->mutexes.write_lock);
				return (NULL);
			}
			pthread_mutex_unlock(philos->mutexes.meal_lock);
			i++;
		}
		if (is_all_eat(philos))
			return (NULL);
	}
	return (NULL);
}

void	philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->mutexes.left_fork);
	print_action(philo, " has taken a fork");
	pthread_mutex_lock(philo->mutexes.right_fork);
	print_action(philo, " has taken a fork");
	pthread_mutex_lock(philo->mutexes.meal_lock);
	print_action(philo, " is eating");
	philo->times.last_meal = get_current_time();
	philo->meals_eaten += 1;
	pthread_mutex_unlock(philo->mutexes.meal_lock);
	ft_usleep(philo->times.eat);
	pthread_mutex_unlock(philo->mutexes.left_fork);
	pthread_mutex_unlock(philo->mutexes.right_fork);
	print_action(philo, " is sleeping");
	ft_usleep(philo->times.sleep);
	print_action(philo, " is thinking");
}

void	*start_simulation(void *ptr)//the function that give birth to the threads
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	pthread_mutex_lock(philo->mutexes.meal_lock);
	philo->times.born_time = get_current_time();//initialize there born time
	philo->times.last_meal = get_current_time();//initialize there last meal time
	pthread_mutex_unlock(philo->mutexes.meal_lock);
	while (1)
		philo_routine(philo);
	return (NULL);
}

void	launcher(t_engine *engine, int count)
{
	t_id	obsorver_id;
	int		i;

	i = 0;
	if (pthread_create(&obsorver_id, NULL, &obsorver, engine->philos) != 0)
		destroy_all(engine, "[Thread Creation ERROR]\n", count, 1);
	while (i < count)
	{
		if (pthread_create(&engine->philos[i].thread_id, NULL,
				start_simulation, &engine->philos[i]) != 0)
			destroy_all(engine, "[Thread Creation ERROR]\n", count, 1);
		i++;
	}
	i = 0;
	if (pthread_join(obsorver_id, NULL) != 0)
		destroy_all(engine, "[Thread Join ERROR]\n", count, 1);
	while (i < count)
	{
		if (pthread_detach(engine->philos[i].thread_id) != 0)
			destroy_all(engine, "[Thread Detach ERROR]\n", count, 1);
		i++;
	}
}
