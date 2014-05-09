#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "philo.h"
#include "libft.h"
#include <unistd.h>


void		output_status(t_philo **ph)
{
	int		i;
	int		time;

	time = TIMEOUT;
	i = 0;
	while (42)
	{
		if (i == NUM_THREADS)
		{
			sleep(1);
			i = 0;
			time--;
			ft_putstr("\n");
		}
		pthread_mutex_lock(&wisemen);
		ft_putstr("philosopher num ");
		ft_putnbr(ph[i]->num);
		ft_putstr(" life is ");
		ft_putnbr(ph[i]->life);
		ft_putstr("and he is ");
		if (ph[i]->status == RESTING)
		ft_putstr("resting");
		if (ph[i]->status == EATING)
		ft_putstr("eating");
		if (ph[i]->status == THINKING)
		ft_putstr("thinking");
		if (ph[i]->status == DEAD || time == 0)
			break;
		pthread_mutex_unlock(&wisemen);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("LETS DANCE");
}

void		create_threads(t_philo **ph, pthread_attr_t *attr, pthread_t *thread)
{
	int		i;
	int		rc;

	i = 0;
	while(i < NUM_THREADS)
	{
		rc = pthread_create(&thread[i], attr, philo, (void *)ph[i]); 
		if (rc)
		{
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
		i++;
	}
}

void	join_with_main(pthread_t *thread)
{
	int		i;
	int		rc;
	void	*ph;

	i = 0;
	while (i < NUM_THREADS)
	{
		rc = pthread_join(thread[i], &ph); 
		if (rc)
		{
			ft_putstr("joining failed\n");
			exit(-1);
		}
		i++;
		ft_putstr("joining succes\n");
	}
}

int main ()
{
	pthread_t		thread[NUM_THREADS];
	t_philo			**ph;
	pthread_attr_t	attr;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	ph = init_ph();
	create_threads(ph, &attr, thread);
	output_status(ph);
	pthread_attr_destroy(&attr);
	join_with_main(thread);
	pthread_exit(NULL);
}
