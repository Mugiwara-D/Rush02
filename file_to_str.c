/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:01:13 by maderuel          #+#    #+#             */
/*   Updated: 2022/10/01 15:03:23 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
char	*ft_open(char *file)
{
	char *nbf;
	int	fd;
	int b;
	int	c;
	
	nbf = (char *) malloc(700 * sizeof(char));
	fd = open(file, O_RDONLY );
	if (fd < 0)
	{
		printf("ERROR");
		return (NULL);
	}
	b = read(fd,nbf,700);
	if (b < 0)
	{
		printf("error");
		return (NULL);
	}
	nbf[b] = '\0';
	c = close(fd);
	if (c < 0)
	{
		printf("erno");
		return (NULL);
	}
	return(nbf);
}
