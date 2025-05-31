/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azha <ael-azha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:12:29 by ael-azha          #+#    #+#             */
/*   Updated: 2025/05/31 16:20:43 by ael-azha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>
# include <stdio.h>

# define RESET    "\033[0m"
# define RED      "\033[31m"
# define GREEN    "\033[32m"

# define PHILO_MAX_COUNT 200
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef pthread_t		t_id;
typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_timeval;

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
	int			meals_eaten;
	int			philo_count;
	int			must_eat;
	t_times		times;
	t_mutexes	mutexes;
	t_id		thread_id;
}	t_philo;

typedef struct s_engine
{
	t_mutex	*forks;//Array of forks(mutexes)
	t_philo	*philos;//Array of philos(threads)
	t_mutex	meal_lock;//mutex locked the meal (checking if all philo have eat)
	t_mutex	write_lock;//mutex write there is locked (printing message)
}	t_engine;

#endif   /* PHILO_H */
