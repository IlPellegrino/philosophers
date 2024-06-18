/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:36:02 by nromito           #+#    #+#             */
/*   Updated: 2024/06/18 15:36:25 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	check_death()
{
	
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		usleep(100);
	while (!philo->data->death)
	{
		eat(philo);
		dream(philo);
		think(philo);
		if (check_death())
			philo->data->death = 1;
	}
}

void	create_philos(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
		if (pthread_create(&data->philo[i].thread_id, NULL, &philo_routine,
			&data->philo[i]) != 0)
			destroy_all("Thread creation failed\n", philo, data);
	i = -1;
	while (++i < data->n_philos)
		if (pthread_join(&data->philo[i].thread_id, NULL) != 0)
			destroy_all("Join thread failed", philo, data);
	
	
	
}
