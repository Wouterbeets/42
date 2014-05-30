/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_to_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 21:45:31 by wbeets            #+#    #+#             */
/*   Updated: 2014/05/30 23:00:43 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <sys/shm.h>
#include <errno.h>

void	connect_to_mem(char team)
{
	t_map	*map;
	int		id;
	
	map = NULL;
	if ((id = shmget(ftok(getenv("PWD"), 0), sizeof(t_map), 0666)) < 0 && errno == ENOENT)
	{
		id = erq(-1, shmget(ftok(getenv("PWD"), 0), sizeof(t_map), 0666 | IPC_CREAT),"Can't create memory\n");
		map = shmat(id, NULL, 0);
		init_map(map);
	}
	else if(erq(-1, id, "shmget error\n"))
	{
		map = shmat(id, NULL, 0);
	}
	put_player(map, team);	
}
