#include "philo.h"
#include <pthread.h>
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int		l_av(t_philo *ph)
{
	if (ph->left_ph->right_hand == FULL && ph->left_ph->status == RESTING)
		return (1);
	return (0);
}

static int		r_av(t_philo *ph)
{
	if (ph->right_ph->left_hand == FULL &&ph->right_ph->status == RESTING)
		return (1);
	return (0);
}

static int		most_life(t_philo *ph)
{
	if (ph->right_ph->life < ph->life && ph->right_ph->status != EATING &&
			ph->left_ph->life < ph->life && ph->left_ph->status  != EATING)
		return (1);
	return (0);
}

static int		least_life(t_philo *ph)
{
	if ((ph->right_ph->life > ph->life || ph->right_ph->status == EATING) &&
			((ph->left_ph->life > ph->life || ph->left_ph->status  == EATING)))
		return (1);
	return (0);
}

static int		same_life(t_philo *ph)
{
	if (ph->life == ph->left_ph->life && ph->life == ph->right_ph->life && ph->left_ph->status != EATING && ph->right_ph->status != EATING && ph->status != EATING)
	{
		return (1);
	}
	return (0);
}

static void	take_right(t_philo *ph)
{
	ph->right_ph->left_hand = EMPTY;
	ph->right_hand = FULL;
	if (ph->left_hand == FULL)
		ph->status = EATING;
	else
		ph->status = THINKING;
}

static void	take_left(t_philo *ph)
{
	ph->left_ph->right_hand = EMPTY;
	ph->left_hand = FULL;
	if (ph->right_hand == FULL)
		ph->status = EATING;
	else
		ph->status = THINKING;
}

static int	have_sticks(t_philo *ph)
{
	if (ph->left_hand == FULL && ph->right_hand == FULL)
		return (1);
	return (0);
}

void	choose_action(t_philo *ph)
{
	pthread_mutex_lock(&wisemen);
	ft_putstr("start of choosing \n");
	if (same_life(ph))
	{
		ft_putstr("same life \n");
		if (r_av(ph))
		{
			ft_putstr("r_av\t");
			take_right(ph);
		}
		if (l_av(ph))
		{
			ft_putstr("l_av\t");
			take_left(ph);
		}
		if (have_sticks(ph))
		{
			ph->status = EATING;
			ft_putstr("have sticks\t");
		}
	}
	else if (most_life(ph))
	{
		ft_putstr("most life\n");
		ph->status = RESTING;
	}
	else if (least_life(ph))
	{
		ft_putstr("least life\n");
		if (r_av(ph))
			take_right(ph);
		if (l_av(ph))
			take_left(ph);
		if (have_sticks(ph))
			ph->status = EATING;
		else if (ph->left_hand == FULL || ph->right_hand == FULL)
			ph->status = THINKING;
		else
			ph->status = RESTING;
	}
	ft_putstr("end \n");
	pthread_mutex_unlock(&wisemen);
}
