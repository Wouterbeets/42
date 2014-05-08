#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "philo.h"
#include "libft.h"
#include <unistd.h>


void		output_status(t_philo **ph)
{
	int		i;

	i = 0;
	while (42)
	{
		if (i == NUM_THREADS)
		{
			sleep(1);
			i = 0;
		}
		ft_putstr("philosopher num ");
		ft_putnbr(ph[i]->num);
		ft_putstr(" is ");
		ft_putnbr(ph[i]->status);
		ft_putstr("\n ");
		if (ph[i]->status == DEAD)
			break;
		i++;
	}
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
 
	printf("Main: program completed. Exiting.\n");
	pthread_exit(NULL);
}
/*
 *	for(i=0; i<NUM_THREADS; i++)
	{
		rc = pthread_join(thread[i], &status);
		if (rc)
		{
			 printf("ERROR; return code from pthread_join is %d\n", rc);
			 exit(-1);
		}
		printf("Main: completed join with thread number %d\n", ((t_philo *)status)->status );
    }
*/
