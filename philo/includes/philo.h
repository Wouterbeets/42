
# define NUM_THREADS	7
# define MAX_LIFE		90
# define EAT_T			10	
# define REST_T			12
# define THINK_T		4
# define TIMEOUT		2000
# define RESTING		0
# define THINKING		1
# define EATING			2
# define DEAD			3

typedef struct		s_philo
{
	int		status;
	int		life;
	int		left_hand;
	int		right_hand;
}					t_philo;
