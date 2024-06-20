/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:00:54 by nromito           #+#    #+#             */
/*   Updated: 2024/06/20 18:41:08 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <sys/time.h>
# include <unistd.h>
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
	int				meals_eaten;
	struct s_data	*data;
	t_mutex			*dx_fork;
	t_mutex			*sx_fork;
	t_mutex			*eating;
	t_mutex			*print;
	t_mutex			*death;
	pthread_t		thread_id;
}			t_philo;

typedef struct s_data
{
	int				n_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		n_times_to_eat;
	size_t			start_time;
	int				death;
	t_mutex			death_lock;
	t_mutex			eating;
	t_mutex			print;
	pthread_t		check;
}			t_data;

/* check death and meal */
void	*monitor(void *pointer);
int		is_not_dead(t_philo *philo);
int		everybody_ate(t_philo *philo);

/* init functions */
void	init_program(t_data *data, char **argv);
int		init_forks(t_mutex *forks, t_data *data);
void	init_philos(t_philo *philo, t_data *data, t_mutex *forks);

/* actions */
void	eat(t_philo *philo);
void	dream(t_philo *philo);
void	think(t_philo *philo);

/* utils */
void	print_message(char *str, t_philo *philo, int id);
size_t	get_real_time(void);
void	destroy_all(char *str, t_philo *philo, t_data *data);

/* routine */
void	create_philos(t_philo *philo, t_data *data);

# endif
