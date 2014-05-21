/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 18:17:46 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/21 17:04:17 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "client.h"
#include "libft.h"
#include <stdlib.h>

void	free_tab(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
}

int		create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (!proto)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	connect(sock, (const struct sockaddr *)&sin, sizeof(sin));
	return (sock);	
}

void	write_server(int sock, char *name)
{
	if (send(sock, name, ft_strlen(name), 0) < 0)
	{
		ft_putstr("\033[31msend() error\033[0m\n");
		exit(0);
	}
}

int		read_server(int sock, char *buf)
{
	int		r;

	if ((r = recv(sock, buf, BUF_SIZE - 1, 0)) < 0)
	{
		ft_putstr("\033[31mread_server() error\033[0m\n");
		exit(0);
	}
	buf[r] = 0;
	return (r);
}

void	action(int sock)
{
		char	name[] = "test";
		char	buf[BUF_SIZE];
		fd_set	readfd;
		int		ret;
		int		r;

		write_server(sock, name);
		while (42)
		{
			FD_ZERO(&readfd);
			FD_SET(sock, &readfd);
			if ((ret = select(sock + 1, &readfd, NULL, NULL, NULL)) < 0)
			{
				ft_putstr("\033[31mselect() problem\033[0m\n");
				exit(0);
			}
			if (FD_ISSET(1, &readfd))
			{
				while ((r = read(1, buf, BUF_SIZE - 1)) > 0)
				{
					buf[r - 1] = 0;
				}
				write_server(sock, buf);
			}
			else if (FD_ISSET(sock, &readfd))
			{
				

				r =	read_server(sock, buf);
				if (r == 0)
				{
					ft_putstr("\033[31mServer disconnected\033[0m\n");
					break ;
				}
				ft_putstr(buf);
			}
		}
}

int		main(int ac, char **av)
{
	int					port;
	int					sock;
	
	if (ac != 3)
	{
		ft_putstr("[USAGE] - ./client [address] [port]\n");
		return (0);
	}
	port = ft_atoi(av[2]);
	sock = create_client(av[1], port);
	action(sock);
	close(sock);
	return (0);
}
