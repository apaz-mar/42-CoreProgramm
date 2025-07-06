/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:50:24 by apaz-mar          #+#    #+#             */
/*   Updated: 2025/07/05 13:09:50 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_rules
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	log_mutex;
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_required;
	long			start_time;
	int				someone_died;
}	t_rules;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
	t_rules			*rules;
}	t_philo;

void	*philo_routine(void *arg);
void	*monitor_routine(void *arg);
void	print_log(t_philo *philo, char *msg);
long	current_timestamp(void);
int		ft_atoi(const char *str);
int		is_positive_number(const char *str);
int		error_exit(const char *msg);
int		ft_atoi(const char *nptr);

#endif /*PHILOSOPHERS_H*/
