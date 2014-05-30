/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 13:52:36 by wbeets            #+#    #+#             */
/*   Updated: 2014/05/31 00:10:34 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H_
# define HEADER_H_
# define WIDTH 30
# define HEIGHT 30
# define EMPTY '.'
# include "struct.h"

int		error(int err, int res, char *msg);
int		erq(int err, int res, char *msg);
void	init_map(t_map *map);
void	connect_to_mem(char team);
void	place_rand(int *i, int *j, t_map *map);
void	do_match(t_map *map, int x, int y, char team);
void	put_player(t_map *map, char my_team);

#endif /* !HEADER_H_ */
