/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:00:54 by nromito           #+#    #+#             */
/*   Updated: 2024/06/25 16:37:49 by nromito          ###   ########.fr       */
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

typedef struct s_data
{
	int				death_prove;
	t_mutex			print;
	t_mutex			death;
	int				n_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			n_times_to_eat;
}			t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	int				is_eating;
	size_t			start_time;
	size_t			last_meal;
	t_mutex			dx_fork;
	t_mutex			sx_fork;
	t_mutex			eating;
	t_data			*data;
	pthread_t		thread_id;
}			t_philo;


/* check death and meal */
void	*monitor(void *pointer);
int		philo_died(t_philo *philo);
int		is_dead(t_philo *philos[MAX_PHILO]);
int		everybody_ate(t_philo *philo);

/* init functions */
int		init_forks(t_mutex *forks, char **argv);
void	init_philos(t_philo *philo[MAX_PHILO], t_mutex *forks, char **argv, t_data *data);

/* actions */
void	eat(t_philo *philo);
void	dream(t_philo *philo);
void	think(t_philo *philo);

/* utils */
void	print_message(char *str, t_philo *philo, int id);
size_t	get_real_time(void);
void	destroy_all(char *str, t_mutex *forks, t_philo *philo[MAX_PHILO], t_data *data);

/* routine */
// int		check_death(t_philo *philo);
void	create_philos(t_philo *philo[MAX_PHILO], t_mutex *forks, t_data *data);

# endif
