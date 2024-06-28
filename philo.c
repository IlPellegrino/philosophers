/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:00:11 by nromito           #+#    #+#             */
/*   Updated: 2024/06/28 11:05:58 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philo.h"

int	check_if_digit(char *to_check)
{
	int	i;

	i = -1;
	while (to_check[++i])
	{
		if (!ft_isdigit(to_check[i]))
			return (1);
	}
	return (0);
}

int	check_args(char **argv)
{
	if (ft_atoi(argv[1]) > 300 || ft_atoi(argv[1]) <= 0
		|| check_if_digit(argv[1]) == 1)
		return (write(2, "Wrong number of philosophers\n", 30), 1);
	if (ft_atoi(argv[2]) <= 0 || check_if_digit(argv[2]) == 1)
		return (write(2, "Wrong time to die\n", 19), 1);
	if (ft_atoi(argv[3]) <= 0 || check_if_digit(argv[3]) == 1)
		return (write(2, "Wrong time to eat\n", 19), 1);
	if (ft_atoi(argv[4]) <= 0 || check_if_digit(argv[4]) == 1)
		return (write(2, "Wrong time to sleep\n", 21), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_if_digit(argv[5]) == 1))
		return (write(2, "Wrong number of times each philo eats\n", 39), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (check_args(argv) == 1)
			return (1);
		init_data(&data, argv);
		init_forks(&data);
		init_philos(argv, &data);
		create_philos(&data);
		destroy_all(NULL, &data);
	}
	else
		return (write(2, "Invalid number of arguments\n", 29), 0);
	return (0);
}
