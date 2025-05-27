/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azha <ael-azha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:23:15 by ael-azha          #+#    #+#             */
/*   Updated: 2025/05/27 22:08:38 by ael-azha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	check_input(int ac, char **av)
{
	int		i;
	long	num;

	i = 0;
	if (ac != 5 && ac != 6)
		printf("Error: Invalide argument\n");
	while (++i < ac)
	{
		num = ft_atoi(av[i]);
		if (i == 1 && (num < 1 || num > PHILO_MAX_COUNT))
			printf ("Error: IInvalide agrument\n");
		else if (i == 5 && (num < 1 || num > INT_MAX))
			printf("Error: Invalide argument\n");
		else if (i != 1 && i != 5 && (num < 1 || num > INT_MAX))
			printf("Error: Invalide argument\n");
		i++;
	}
}

int main(int ac, char **av)
{
	t_philo		philos[PHILO_MAX_COUNT];
	t_mutex		forks[PHILO_MAX_COUNT];
	t_engine	engine;

	check_input(ac, av);
}
