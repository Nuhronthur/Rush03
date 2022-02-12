/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonvella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:24:23 by jonvella          #+#    #+#             */
/*   Updated: 2022/02/12 17:22:12 by jonvella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 4096

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	rtu(char *str, int nb)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < nb)
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	while (str[i] != ':')
		{
			i++;
		}
	i++;

	while (str[i] != '\n')
	{
		while (str[i] == ' ')
		{
			i++;
		}
		ft_putchar(str[i]);
		i++;
	}
}

