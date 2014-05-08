#include "philo.h"
#include <pthread.h>
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void		*philo(void *data)
{
	t_philo		*ph;

	ph =(t_philo *)data;
	while (42)
	{
		sleep(1);
		pthread_mutex_lock(&wisemen[ph->num]);
		ph->life -= 1;
		if (ph->life <= 0)
		{
			ph->status = DEAD;
			pthread_exit((void *)ph);
		}
		pthread_mutex_unlock(&wisemen[ph->num]);
	}
}

