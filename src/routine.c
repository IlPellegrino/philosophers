/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:36:02 by nromito           #+#    #+#             */
/*   Updated: 2024/06/24 17:03:24 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(philo->death);
	if (philo->death_prove == 1)
		return (pthread_mutex_unlock(philo->death), 1);
	return (pthread_mutex_unlock(philo->death), 0);
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		usleep(200);
	while (!check_death(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (pointer);
}

void	create_philos(t_philo *philo, t_mutex *forks)
{
	int			i;
	pthread_t	ref;

	i = -1;
	philo->start_time = get_real_time();
	if (pthread_create(&ref, NULL, &monitor, philo) != 0)
		destroy_all("Thread creation failed\n", forks, philo);
	while (++i < philo->n_philos)
		if (pthread_create(&philo[i].thread_id, NULL, &philo_routine,
			&philo[i]) != 0)
			destroy_all("Thread creation failed\n", forks, philo);
	i = -1;
	if (pthread_join(ref, NULL) != 0)
		destroy_all("Join thread failed\n", forks, philo);
	while (++i < philo->n_philos)
		if (pthread_join(philo[i].thread_id, NULL) != 0)
			destroy_all("Join thread failed\n", forks, philo);
}
