/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:50:57 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/07/05 13:16:44 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_death(t_philo *philos, t_rules *rules)
{
	int		i;
	long	now;

	i = 0;
	while (i < rules->num_philos)
	{
		pthread_mutex_lock(&philos[i].meal_mutex);
		now = current_timestamp();
		if (now - philos[i].last_meal > rules->time_to_die)
		{
			pthread_mutex_unlock(&philos[i].meal_mutex);
			print_log(&philos[i], "died");
			pthread_mutex_lock(&rules->log_mutex);
			rules->someone_died = 1;
			pthread_mutex_unlock(&rules->log_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philos[i].meal_mutex);
		i++;
	}
	return (0);
}

int	check_meals(t_philo *philos, t_rules *rules)
{
	int	i;
	int	full_count;

	if (rules->meals_required <= 0)
		return (0);
	full_count = 0;
	i = 0;
	while (i < rules->num_philos)
	{
		pthread_mutex_lock(&philos[i].meal_mutex);
		if (philos[i].meals_eaten >= rules->meals_required)
			full_count++;
		pthread_mutex_unlock(&philos[i].meal_mutex);
		i++;
	}
	if (full_count == rules->num_philos)
	{
		pthread_mutex_lock(&rules->log_mutex);
		rules->someone_died = 1;
		pthread_mutex_unlock(&rules->log_mutex);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philos;
	t_rules	*rules;

	philos = (t_philo *)arg;
	rules = philos[0].rules;
	while (1)
	{
		if (check_meals(philos, rules))
			return (NULL);
		if (check_death(philos, rules))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
