/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 21:19:48 by wbeets            #+#    #+#             */
/*   Updated: 2014/05/30 22:50:08 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/shm.h> 
#include "header.h"


int		main(int ac, char **av)
{
	if (ac != 2)
		erq(-1, -1,"usage: ./lemipc [team letter or number]");
	connect_to_mem(av[1][0]);
	return (0);
}
