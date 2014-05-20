/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 14:41:48 by wbeets            #+#    #+#             */
/*   Updated: 2014/05/20 14:41:59 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include "serveur.h"

void			srv_create(t_env *e, int port)
{
	int			s;
	struct sockaddr_in	sin;
	struct protoent	*pe;

	pe = (struct protoent*)Xv(NULL, getprotobyname("tcp"), "getprotobyname");
	s = X(-1, socket(PF_INET, SOCK_STREAM, pe->p_proto), "socket");
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(port);
	X(-1, bind(s, (struct sockaddr*)&sin, sizeof(sin)), "bind");
	X(-1, listen(s, 42), "listen");
	e->fds[s].type = FD_SERV;
	e->fds[s].fct_read = srv_accept;
}
