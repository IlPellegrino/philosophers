/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:00:54 by nromito           #+#    #+#             */
/*   Updated: 2024/06/12 16:43:48 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>
# include <stdlib.h>

typedef pthread_mutex_t		t_mutex;

typedef struct s_philo
{
	int				id;
	struct s_data	*data;
	struct s_philo	*next;
	t_mutex			*fork;
	pthread_t		thread;
}			t_philo;

typedef struct s_data
{
	long		n_philos;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		start_time;
	t_mutex		*death;
	t_mutex		*writing;
	t_philo		*philo;
	pthread_t	check;
}			t_data;




# endif
