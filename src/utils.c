/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:54:46 by nromito           #+#    #+#             */
/*   Updated: 2024/06/25 16:27:01 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	destroy_forks(t_mutex *forks, t_philo *philos[MAX_PHILO])
{
	int	i;

	i = -1;
	while (++i < philos[0]->data->n_philos)
		pthread_mutex_destroy(&forks[i]);
}

void	destroy_all(char *str, t_mutex *forks, t_philo *philos[MAX_PHILO], t_data *data)
{
	int	i;

	i = -1;
	if (str)
		ft_putstr_fd(str, 2);
	if (pthread_mutex_destroy(&data->death) != 0
		|| pthread_mutex_destroy(&data->print) != 0)
	{
		write(2, "Failed to destroy mutex\n", 25);
	}
	while (++i < data->n_philos)
	{
		if (pthread_mutex_destroy(&philos[i]->eating)!= 0)
		{
			write(2, "Failed to destroy mutex\n", 25);
			return ;
		}
	}
	destroy_forks(forks, philos);
}

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	real_time;

	pthread_mutex_lock(&philo->data->print);
	real_time = get_real_time() - philo->start_time;
	if (philo->data->death_prove == 0)
		printf("%zu %d %s\n", real_time, id, str);
	pthread_mutex_unlock(&philo->data->print);
}

size_t	get_real_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
