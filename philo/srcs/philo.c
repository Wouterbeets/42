#include "philo.h"
#include <pthread.h>
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static void		lose_life(t_philo *ph)
{
	sleep(1);
	pthread_mutex_lock(&wisemen);
	ph->life -= 1;
	if (ph->life <= 0)
	{
		ph->status = DEAD;
		pthread_exit((void *)ph);
	}
	pthread_mutex_unlock(&wisemen);
}

static void		eating(t_philo *ph)
{
	sleep(EAT_T);
	pthread_mutex_lock(&wisemen);
	ph->life = MAX_LIFE;
	pthread_mutex_unlock(&wisemen);
}

static void		thinking(t_philo *ph)
{
	int		i;

	i = 0;
	while (i < THINK_T)
	{
		lose_life(ph);
		i++;
	}
}

static void		resting(t_philo *ph)
{
	int		i;

	i = 0;
	while (i < REST_T)
	{
		lose_life(ph);
		i++;
	}
}

void		*philo(void *data)
{
	t_philo		*ph;

	ph =(t_philo *)data;
	while (42)
	{
		choose_action(ph);
		if (ph->status == RESTING)
			resting(ph);
		else if (ph->status == THINKING)
			thinking(ph);
		else if (ph->status == EATING)
			eating(ph);
	}
}
