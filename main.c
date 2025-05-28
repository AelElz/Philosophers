/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azha <ael-azha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:23:15 by ael-azha          #+#    #+#             */
/*   Updated: 2025/05/28 13:13:53 by ael-azha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	check_input(int ac, char **av)
{
	int		i;
	long	num;

	i = 1;
	while (i < ac)
	{
		if (only_digits(av[i]))
		{
			num = ft_atoi(av[i]);
			if (i == 1 && (num <= 0 || num > PHILO_MAX_COUNT))
				printf("Error: Too much philosophers\n");
			else if (i == 2 && num <= 0)
				printf("Error: time_to_die must be over 0\n");
			else if (i != 1 && num <= 0)
				printf("Error: the number should be over 0\n");
		}
		else
		{
			printf("Error: write only numbers\n");
			return ;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	//t_philo		philos[PHILO_MAX_COUNT];
	//t_mutex		forks[PHILO_MAX_COUNT];
	//t_engine	engine;
	if (ac != 5 && ac != 6)
		printf("you should write 5 or 6 argument\n");
	check_input(ac, av);
	//philosopher(num_of_philo, time_to_die, time_to_eat, time_to_sleep);
}
