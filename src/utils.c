/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:54:46 by nromito           #+#    #+#             */
/*   Updated: 2024/06/20 10:25:07 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	destroy_all(char *str, t_philo *philo, t_data *data)
{
	pthread_mutex_destroy(philo->sx_fork);
	pthread_mutex_destroy(philo->dx_fork);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->eating);
	if (str)
		printf("%s", str);
}

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	real_time;

	pthread_mutex_lock(philo->print);
	real_time = get_real_time();
	real_time -= philo->data->start_time;
	// if (is_not_dead(philo))
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
