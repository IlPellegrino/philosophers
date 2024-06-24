/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:54:46 by nromito           #+#    #+#             */
/*   Updated: 2024/06/24 17:20:40 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	destroy_forks(t_mutex *forks, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo[0].n_philos)
		pthread_mutex_destroy(&forks[i]);
}

void	destroy_all(char *str, t_mutex *forks, t_philo *philo)
{
	int	i;

	i = -1;
	if (str)
		ft_putstr_fd(str, 2);
	while (++i < philo->n_philos)
	{
		// pthread_mutex_unlock(philo[i].death);
		pthread_mutex_destroy(philo[i].death);
		// pthread_mutex_unlock(philo[i].print);
		pthread_mutex_destroy(philo[i].print);
		// pthread_mutex_unlock(philo[i].eating);
		pthread_mutex_destroy(philo[i].eating);
	}
	destroy_forks(forks, philo);
}

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	real_time;

	pthread_mutex_lock(philo->print);
	real_time = get_real_time() - philo->start_time;
	if (philo->death_prove == 0)
		printf("%zu %d %s\n", real_time, id, str);
	pthread_mutex_unlock(philo->print);
}

size_t	get_real_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
