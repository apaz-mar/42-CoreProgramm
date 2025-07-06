/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:51:18 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/07/05 13:14:28 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	assym_grab(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_log(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_log(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_log(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_log(philo, "has taken a fork");
	}
	return ;
}

int	is_simulation_over(t_rules *rules)
{
	int	res;

	pthread_mutex_lock(&rules->log_mutex);
	res = rules->someone_died;
	pthread_mutex_unlock(&rules->log_mutex);
	return (res);
}

void	philo_eat_sleep(t_philo *philo)
{
	if (is_simulation_over(philo->rules))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = current_timestamp();
	pthread_mutex_unlock(&philo->meal_mutex);
	print_log(philo, "is eating");
	usleep(philo->rules->time_to_eat * 1000);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_log(philo, "is sleeping");
	usleep(philo->rules->time_to_sleep * 1000);
	usleep(100);
	return ;
}
//printf("Philosopher %d has eaten %d times\n", philo->id, philo->meals_eaten);

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 1)
		usleep(100);
	else
		usleep(50);
	while (!is_simulation_over(philo->rules))
	{
		print_log(philo, "is thinking");
		assym_grab(philo);
		philo_eat_sleep(philo);
		if (is_simulation_over(philo->rules))
			break ;
	}
	return (NULL);
}
