/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:36:02 by nromito           #+#    #+#             */
/*   Updated: 2024/06/28 10:46:55 by nromito          ###   ########.fr       */
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
		eat(philo);
		dream(philo);
		think(philo);
		if (is_finished(philo))
			break ;
	}
	return (pointer);
}

void	create_philos(t_data *data)
{
	int	i;
	int	n_philos;

	i = -1;
	n_philos = data->n_philos;
	while (++i < n_philos)
		if (pthread_create(&data->philos[i].thread_id, NULL, &philo_routine,
				&data->philos[i]) != 0)
			destroy_all("Thread creation failed\n", data);
	i = -1;
	monitor(data);
	while (++i < n_philos)
		if (pthread_join(data->philos[i].thread_id, NULL) != 0)
			destroy_all("Join thread failed\n", data);
}
