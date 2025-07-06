/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:51:25 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/07/05 13:12:27 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_log(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->rules->log_mutex);
	if (!philo->rules->someone_died)
		printf("%ld %d %s\n", current_timestamp() - philo->rules->start_time,
			philo->id, msg);
	pthread_mutex_unlock(&philo->rules->log_mutex);
	return ;
}

long	current_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	is_positive_number(const char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	error_exit(const char *msg)
{
	printf("%s\n", msg);
	return (1);
}
