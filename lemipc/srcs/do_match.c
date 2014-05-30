/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 23:29:41 by wbeets            #+#    #+#             */
/*   Updated: 2014/05/31 00:06:21 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <time.h>
#include <libft.h>

void	print_map(t_map *map)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	system("clear");
	while (y < HEIGHT)
	{
		while(x < WIDTH)
		{
			ft_putchar(map->map[y][x]);
			x++;
		}
		x = 0;
		ft_putchar('\n');
		y++;
	}
	
}


void	do_match(t_map *map, int x, int y, char team)
{
	int		dir;
	while (42)
	{
		srand(time(NULL) + y);
		dir = rand() % 4;
		if (dir == 0 && y > 0 && y < HEIGHT - 1 && map->map[y - 1][x] == EMPTY)
		{
			map->map[y][x] = EMPTY;
			map->map[y -1][x] = team;
		}
		if (dir == 1 && y == 0 && y < HEIGHT - 1 && map->map[y + 1][x] == EMPTY)
		{
			map->map[y][x] = EMPTY;
			map->map[y + 1][x] = team;
		}
		if (dir == 2 && x > 0 && y < WIDTH - 1 && map->map[y][x - 1] == EMPTY)
		{
			map->map[y][x] = EMPTY;
			map->map[y][x - 1] = team;
		}
		if (dir == 3 && x > 0 && y < WIDTH - 1 && map->map[y - 1][x] == EMPTY)
		{
			map->map[y][x] = EMPTY;
			map->map[y -1][x] = team;
		}
		sleep(1);
		print_map(map);
	}
}
