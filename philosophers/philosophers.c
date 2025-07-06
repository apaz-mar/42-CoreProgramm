/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:51:07 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/07/05 14:40:29 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_rules(t_rules *rules, int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (error_exit("Usage: ./philo num die eat sleep [meals]"));
	i = 1;
	while (i < argc)
	{
		if (!is_positive_number(argv[i]))
			return (error_exit("Error: all args must be > 0"));
		i++;
	}
	rules->num_philos = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rules->meals_required = ft_atoi(argv[5]);
	else
		rules->meals_required = -1;
	rules->someone_died = 0;
	return (0);
}

int	init_simulation(t_rules *rules, t_philo **philos)
{
	int	i;

	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->num_philos);
	*philos = malloc(sizeof(t_philo) * rules->num_philos);
	if (!rules->forks || !*philos)
		return (1);
	pthread_mutex_init(&rules->log_mutex, NULL);
	i = 0;
	while (i < rules->num_philos)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < rules->num_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].rules = rules;
		(*philos)[i].left_fork = &rules->forks[i];
		(*philos)[i].right_fork = &rules->forks[(i + 1) % rules->num_philos];
		pthread_mutex_init(&(*philos)[i].meal_mutex, NULL);
		i++;
	}
	return (0);
}

int	start_threads(t_rules *rules, t_philo *philos)
{
	pthread_t	monitor_thread;
	int			i;

	rules->start_time = current_timestamp();
	i = 0;
	while (i < rules->num_philos)
	{
		philos[i].last_meal = current_timestamp();
		if (pthread_create(&philos[i].thread, NULL,
				philo_routine, &philos[i]) != 0)
			return (1);
		i++;
	}
	if (pthread_create(&monitor_thread, NULL, monitor_routine, philos) != 0)
		return (1);
	if (rules->num_philos == 1)
		pthread_detach(philos[0].thread);
	else
	{
		i = 0;
		while (i < rules->num_philos)
			pthread_join(philos[i++].thread, NULL);
	}
	pthread_join(monitor_thread, NULL);
	return (0);
}

void	cleanup(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rules->num_philos)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		pthread_mutex_destroy(&philos[i].meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&rules->log_mutex);
	free(rules->forks);
	free(philos);
}

int	main(int argc, char **argv)
{
	t_rules	rules;
	t_philo	*philos;

	if (init_rules(&rules, argc, argv))
		return (1);
	if (init_simulation(&rules, &philos))
		return (1);
	if (start_threads(&rules, philos))
		return (1);
	cleanup(&rules, philos);
	return (0);
}
