/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 14:38:38 by wbeets            #+#    #+#             */
/*   Updated: 2014/05/21 20:03:54 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "serveur.h"

void	client_read(t_env *e, int cs)
{
	int	r;
	int	i;

		i = 0;
	r = recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0);
	if (r <= 0)
	{
		close(cs);
		clean_fd(&e->fds[cs]);
		printf("client #%d gone away\n", cs);
	}
	else
	{
		while (i <= r)
		{
			e->fds[cs].buf_write[i] = e->fds[cs].buf_read[i];
			i++;
		}
		e->fds[cs].buf_write[i] = '\0';
	}
}
