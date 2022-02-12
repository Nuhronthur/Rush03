/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonvella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:24:23 by jonvella          #+#    #+#             */
/*   Updated: 2022/02/12 18:07:22 by jonvella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 691
int	ft_atoi(char *str);

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
			i++;
		ft_putchar(str[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	char res[BUF_SIZE];
	int	fd;
	int r;

	fd = open("numbers.dict.txt", O_RDONLY);
	r = read(fd, res, BUF_SIZE); 
//	printf("%s", &res);
	rtu(res, ft_atoi(av[1]));
}
