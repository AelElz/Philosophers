/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azha <ael-azha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:12:25 by ael-azha          #+#    #+#             */
/*   Updated: 2025/05/31 16:12:27 by ael-azha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "philo.h"

void	init_philos(t_engine *en, t_philo *philos, t_mutex *forks, char **argv);
void	init_forks(t_engine *engine, t_mutex *forks, int count);
void	init_engine(t_engine *engine, t_philo *philos, t_mutex *forks);

#endif   /* INIT_H */
