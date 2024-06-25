/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:36:02 by nromito           #+#    #+#             */
/*   Updated: 2024/06/25 16:31:48 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		usleep(200);
	while (1)
	{
		pthread_mutex_lock(&philo->data->death);
		if (philo->data->death_prove)
			break ;
		pthread_mutex_unlock(&philo->data->death);
		eat(philo);
		dream(philo);
		think(philo);
	}
	pthread_mutex_unlock(&philo->data->death);
	return (pointer);
}

void	create_philos(t_philo *philos[MAX_PHILO], t_mutex *forks, t_data *data)
{
	int			i;
	pthread_t	ref;
	int n_philos = data->n_philos;

	i = -1;
	if (pthread_create(&ref, NULL, &monitor, philos) != 0)
		destroy_all("Thread creation failed\n", forks, philos, data);
	while (++i < n_philos)
		if (pthread_create(&philos[i]->thread_id, NULL, &philo_routine,
			philos[i]) != 0)
			destroy_all("Thread creation failed\n", forks, philos, data);
	i = -1;
	if (pthread_join(ref, NULL) != 0)
		destroy_all("Join thread failed\n", forks, philos, data);
	while (++i < n_philos)
		if (pthread_join(philos[i]->thread_id, NULL) != 0)
			destroy_all("Join thread failed\n", forks, philos, data);
}
