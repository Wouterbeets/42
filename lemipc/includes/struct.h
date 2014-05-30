/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 21:30:24 by wbeets            #+#    #+#             */
/*   Updated: 2014/05/30 22:44:49 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct	s_map
{
	char	map[HEIGHT][WIDTH];
	int		num_player;
}				t_map;

#endif /* !STRUCT_H_ */
