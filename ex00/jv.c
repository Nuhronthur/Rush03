/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonvella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:47:26 by jonvella          #+#    #+#             */
/*   Updated: 2022/02/12 20:13:20 by jonvella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
void	rtu(char *str, int nb);
int	ft_atoi(char *str)
{
	int	i;
	int	m;
	int	r;

	i = 0;
	m = 0;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			m++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	if (m % 2 == 1)
		r *= -1;
	return (r);
}
int	ft_hmt(int nb)
{
	int	i;

	i= 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
int	ft_hmtri(int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb -= 3;
		i++;
	}
	return (i);
}
int	ft_rohff(int nb)
{
	int i;

	i = 1;
	while (nb > 0)
	{
		i *= 10;
		nb--;
	}
	return (i);
}
void	rtn(char *str, int nb)
	{
		int cd;
		int tr;
		int t;

		cd = ft_hmt(nb);	
		tr = ft_hmtri(cd);
		if (tr == 1)
			printf("%i\n",nb);
		else 
		{
			t = nb / (ft_rohff(cd - 1));
			printf("%i\n", t);
			rtn(str, nb - t * ft_rohff(cd - 1)); 
		}
		return ;
	}
int main(int ac, char **av)
{
	char res[691];
	int	fd;
	int r;

	fd = open("numbers.dict.txt", O_RDONLY);
	r = read(fd, res, 691);
	rtn(res, ft_atoi(av[1]));
}
