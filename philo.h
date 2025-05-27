/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azha <ael-azha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:23:24 by ael-azha          #+#    #+#             */
/*   Updated: 2025/05/27 18:18:42 by ael-azha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>	
# include <pthread.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include "includes/libft.h"

# define PHILO_MAX_COUNT 200

typedef pthread_t				t_id;
typedef pthread_mutex_t			t_mutex;
typedef struct s_mutexes		t_timeval;

typedef struct s_mutexes
{
	t_mutex	*left_fork;
	t_mutex	*right_fork;
	t_mutex	*write_lock;
	t_mutex	*meal_lock;
}	t_mutexes;

typedef struct s_times
{
	size_t	die;
	size_t	eat;
	size_t	sleep;
	size_t	last_meal;
	size_t	born_time;
}	t_times;

typedef struct s_philo
{
	int			id;
	t_times		times;
	t_mutexes	mustexes;
	int			must_eat;
	int			meals_eaten;
	int			philo_count;
	t_id		thread_id;
}	t_philo;

typedef struct s_engine
{
	t_mutex	*forks;
	t_philo	*philos;
	t_mutex	meal_lock;
	t_mutex	write_lock;
}	t_engine;
#endif