/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 23:00:19 by wbeets            #+#    #+#             */
/*   Updated: 2014/05/30 23:47:28 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_player(t_map *map, char my_team)
{
	int		x;
	int		y;
	
	x = WIDTH / 2;
	y = HEIGHT / 2;
	place_rand(&x, &y, map);
	do_match(map, x, y, my_team);
}
