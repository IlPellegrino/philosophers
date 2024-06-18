/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:21:05 by nromito           #+#    #+#             */
/*   Updated: 2024/06/18 16:57:31 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	eat(t_philo *philo)
{
	
}

void	dream(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	//ft_usleep()    ???
}

void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}