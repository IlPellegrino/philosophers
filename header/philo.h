/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:00:54 by nromito           #+#    #+#             */
/*   Updated: 2024/06/18 11:02:01 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>
# include <stdlib.h>

# define MAX_PHILO 300

typedef pthread_mutex_t		t_mutex;

typedef struct s_philo
{
	int				id;
	int				times_eaten;
	t_data			*data;
	t_mutex			*dx_fork;
	t_mutex			*sx_fork;
	pthread_t		thread_id;
}			t_philo;

typedef struct s_data
{
	long		n_philos;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		n_times_to_eat;
	long		start_time;
	int			death;
	t_philo		*philo;
	t_mutex		*print;
	pthread_t	check;
}			t_data;

# endif
