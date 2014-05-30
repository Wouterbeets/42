/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_rand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 23:16:27 by wbeets            #+#    #+#             */
/*   Updated: 2014/05/30 23:37:13 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <time.h>

void	place_rand(int *i, int *j, t_map *map)
{
	int		x;
	int		y;

	y = *j;
	x = *i;
	while(x >= WIDTH && y >= HEIGHT && map->map[y][x] != EMPTY)
	{
		srand(time(NULL) + y);
		y = rand() % HEIGHT;
		srand(time(NULL) + x);
		x = rand() % WIDTH;
	}
	*j = y;
	*i = x;
}
