#include "philo.h"
#include <pthread.h>
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int		i_have_most_life(t_philo *ph)
{
	if ((ph->right_ph->life <= ph->life || ph->right_ph->status != EATING) &&
		((ph->left_ph->life <= ph->life || ph->left_ph->status  != EATING)))
		return (1);
	return (0);
}

static int		i_have_least_life(t_philo *ph)
{
	if ((ph->right_ph->life >= ph->life || ph->right_ph->status == EATING) &&
		((ph->left_ph->life >= ph->life || ph->left_ph->status  == EATING)))
		return (1);
	return (0);
}

void	choose_action(t_philo *ph)
{
	//if (pthread_mutex_trylock(&wisemen[ph->num]) && pthread_mutex_lock(&wisemen[ph->left_ph->num]) && pthread_mutex_lock(&wisemen[ph->right_ph->num]))
	{
		if (i_have_least_life(ph))
		{
			ft_putstr("oke");
			if (ph->right_ph->status == RESTING && ph->right_ph->left_hand == FULL &&ph->left_hand == FULL)
			{
				ph->right_ph->left_hand = EMPTY;
				ph->right_hand = FULL;
				ph->status = EATING; 
			}
			if (ph->left_ph->status == RESTING && ph->left_ph->right_hand == FULL)
			{
				ph->right_ph->right_hand = EMPTY;
				ph->left_hand = FULL;
			}
			if (ph->left_hand == FULL && ph->right_hand == FULL)
				ph->status = EATING;
			if ((ph->left_hand == FULL && ph->right_hand == EMPTY) ||
					(ph->right_hand == FULL && ph->left_hand == EMPTY))
				ph->status = THINKING;
			else
				ph->status = RESTING;
		}
		if (ph->status != EATING && (ph->right_ph->status == THINKING || ph->left_ph->status ==  THINKING || i_have_most_life(ph)))
		{
			ph->status = RESTING;
		}
	}
//	pthread_mutex_unlock(&wisemen[ph->num]);
//	pthread_mutex_unlock(&wisemen[ph->left_ph->num]);
//	pthread_mutex_unlock(&wisemen[ph->right_ph->num]);
}
