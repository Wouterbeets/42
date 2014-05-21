/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 14:39:15 by wbeets            #+#    #+#             */
/*   Updated: 2014/05/21 20:09:50 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <unistd.h>
#include "serveur.h"
#include "libft.h"

void	client_write(t_env *e, int cs)
{
	(void)cs;
	(void)e;
	int	 i;
	int		j;
	
	i = 0;
	j = ft_strlen(e->fds[cs].buf_write);
	write(1, "fuck fuck duck\n", 15);
	while (i < e->maxfd)
	{
		if ((e->fds[i].type == FD_CLIENT) && (i != cs))
			send(i, e->fds[cs].buf_write, ft_strlen(e->fds[cs].buf_write), 0);
		i++;
	}
	i = 0;
	while (i <= j)
	{
		e->fds[cs].buf_write[i] = '\0'; 
		i++;
	}
}
