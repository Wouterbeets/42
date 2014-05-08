#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "philo.h"
#include "libft.h"
#include <unistd.h>

pthread_mutex_t wisemen[NUM_THREADS];

void		*philo(void *data)
{
	t_philo		*ph;

	ph =(t_philo *)data;
	while (42)
	{
		ft_putstr("im alive");
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

t_philo		**init_ph(void)
{
	int		i;
	t_philo	**ph;

	ph = (t_philo **)malloc(NUM_THREADS * sizeof(t_philo *));
	i = 0;
	while (i < NUM_THREADS)
	{
		ph[i] = (t_philo *)malloc(sizeof(t_philo));
		pthread_mutex_init(&wisemen[i], NULL);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		ph[i]->status = RESTING;
		ph[i]->left_hand = FULL;
		ph[i]->right_hand = EMPTY;
		if (i == 0)
			ph[i]->left_ph = ph[NUM_THREADS - 1];
		else 
			ph[i]->left_ph = ph[i - 1];
		if (i == NUM_THREADS)
			ph[i]->right_ph = ph[0];
		else
			ph[i]->right_ph = ph[i];
		ph[i]->life = MAX_LIFE;
		ph[i]->num = i;
		i++;
	}
	return (ph);
}

int main ()
{
	pthread_t		thread[NUM_THREADS];
	t_philo			**ph;
	pthread_attr_t	attr;
	int				rc;
	int				i;
	void			*status;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	ph = init_ph();
	i = 0;
	while(i < NUM_THREADS)
	{
		printf("Main: creating thread %d\n", i);
		rc = pthread_create(&thread[i], &attr, philo, (void *)ph[i]); 
		if (rc)
		{
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
		i++;
	}
	pthread_attr_destroy(&attr);
	for(i=0; i<NUM_THREADS; i++)
	{
		rc = pthread_join(thread[i], &status);
      if (rc) {
         printf("ERROR; return code from pthread_join is %d\n", rc);
         exit(-1);
         }
      printf("Main: completed join with thread number %d\n", ((t_philo *)status)->num );
      }
 
	printf("Main: program completed. Exiting.\n");
	pthread_exit(NULL);
}
