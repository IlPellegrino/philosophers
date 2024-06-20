/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:36:02 by nromito           #+#    #+#             */
/*   Updated: 2024/06/20 18:43:25 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		usleep(100);
	// printf("qua va\n");
	while (!philo->data->death)
	{
		eat(philo);
		// printf("qua va\n");
		dream(philo);
		think(philo);
		if (is_not_dead(philo))
			philo->data->death = 1;
		// ricordati di dare il tempo a tutti i philo di joinare con usleep di time to die + time to sleep + time to eat
	}
	return (pointer);
}

void	create_philos(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	philo->data->start_time = get_real_time();
	// if (pthread_create(&data->check, NULL, &monitor, NULL) != 0)
	// 	destroy_all("Thread creation failed\n", philo, data);
	while (++i < data->n_philos)
		if (pthread_create(&philo[i].thread_id, NULL, &philo_routine,
			&philo[i]) != 0)
			destroy_all("Thread creation failed\n", philo, data);
	// printf("qua va\n");
	i = -1;
	// if (pthread_join(&data->check, NULL) != 0)
	// 	destroy_all("Join thread failed\n", philo, data);
	while (++i < data->n_philos)
		if (pthread_join(philo[i].thread_id, NULL) != 0)
			destroy_all("Join thread failed\n", philo, data);
	
	
	
}
