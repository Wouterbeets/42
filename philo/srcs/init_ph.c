
#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

static void		fill_in_vals(t_philo **ph)
{
	int		i;

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
		if (i == NUM_THREADS - 1)
			ph[i]->right_ph = ph[0];
		else
			ph[i]->right_ph = ph[i + 1];
		ph[i]->life = MAX_LIFE;
		ph[i]->num = i;
		i++;
	}
}

t_philo		**init_ph(void)
{
	int		i;
	t_philo	**ph;

	ph = (t_philo **)malloc(NUM_THREADS * sizeof(t_philo *));
	i = 0;
	pthread_mutex_init(&wisemen, NULL);
	while (i < NUM_THREADS)
	{
		ph[i] = (t_philo *)malloc(sizeof(t_philo));
		i++;
	}
	fill_in_vals(ph);
	return (ph);
}
