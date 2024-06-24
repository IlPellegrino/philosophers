/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:00:54 by nromito           #+#    #+#             */
/*   Updated: 2024/06/24 17:10:28 by nromito          ###   ########.fr       */
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
	int				is_eating;
	int				death_prove;
	int				n_philos;
	size_t			start_time;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			n_times_to_eat;
	t_mutex			dx_fork;
	t_mutex			sx_fork;
	t_mutex			*eating;
	t_mutex			*print;
	t_mutex			*death;
	pthread_t		thread_id;
}			t_philo;

typedef struct s_data
{
	t_mutex			eating;
	t_mutex			print;
	t_mutex			death;
}			t_data;

/* check death and meal */
void	*monitor(void *pointer);
int		is_dead(t_philo *philo);
int		everybody_ate(t_philo *philo);

/* init functions */
int		init_forks(t_mutex *forks, char **argv);
void	init_philos(t_philo *philo, t_mutex *forks, char **argv, t_data *data);

/* actions */
void	eat(t_philo *philo);
void	dream(t_philo *philo);
void	think(t_philo *philo);

/* utils */
void	print_message(char *str, t_philo *philo, int id);
size_t	get_real_time(void);
void	destroy_all(char *str, t_mutex *forks, t_philo *philo);

/* routine */
int		check_death(t_philo *philo);
void	create_philos(t_philo *philo, t_mutex *forks);

# endif
