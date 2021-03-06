/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 22:23:31 by wbeets            #+#    #+#             */
/*   Updated: 2014/05/31 00:10:14 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		init_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			map->map[i][j] = EMPTY;
			j++;
		}
		j = 0;
		i++;
	}
}
