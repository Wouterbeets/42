/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 21:21:52 by wbeets            #+#    #+#             */
/*   Updated: 2014/05/30 23:56:18 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		error(int err, int ret, char *msg)
{
	if (err == ret)
		ft_putstr(msg);
	return (ret);
}

int		erq(int err, int ret, char *msg)
{
	if (err == ret)
	{
		ft_putstr(msg);
		exit(-1);
	}
	return (ret);
}

