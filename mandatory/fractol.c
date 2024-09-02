/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:11:49 by hakaraou          #+#    #+#             */
/*   Updated: 2024/03/01 11:43:14 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_space(char *av)
{
	size_t	j;
	size_t	k;

	k = 0;
	j = 0;
	while (av[j])
		j++;
	while (av[k] && (av[k] == '\t' || av[k] == '\n'
			|| av[k] == ' ' || av[k] == '\v'
			|| av[k] == '\f' || av[k] == '\r'))
		k++;
	return (1 * (j == 0 || k == j));
}

static int	check_int1(char *av, int i)
{
	int	k;

	k = 0;
	while (av[i] && av[i] != ' ')
	{
		if (((av[i] < '0' || av[i] > '9') && av[i] != '.')
			|| (av[i] == '.' && k == 1))
			return (1);
		if (av[i] == '.' && k == 0)
		{
			if (av[i + 1] < '0' || av[i + 1] > '9')
				return (1);
			k = 1;
		}
		i++;
	}
	return (0);
}

static int	check_int(char *av)
{
	int	i;

	i = 0;
	while (av[i] == ' ')
		i++;
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (!av[i] || av[i] < '0' || av[i] > '9')
		return (1);
	if (check_int1(av, i))
		return (1);
	while (av[i] && av[i] != ' ')
		i++;
	while (av[i + 1] && av[i] == ' ')
	{
		i++;
		if (av[i] != ' ')
			return (1);
	}
	return (0);
}

static int	ft_check(char *av)
{
	return (1 * (check_space(av) || check_int(av)));
}

int	main(int ac, char **av)
{
	t_data	img;

	if ((ac == 2) && ft_strlen(av[1]) == ft_strlen("mandelbrot")
		&& !ft_strncmp(av[1], "mandelbrot", ft_strlen("mandelbrot")))
	{
		img.fr = 0;
		ft_fractol(img);
		return (0);
	}
	if (ac == 4 && ft_strlen(av[1]) == ft_strlen("julia")
		&& !ft_strncmp(av[1], "julia", ft_strlen("julia")))
	{
		if (!ft_check(av[2]) && !ft_check(av[3]))
		{
			img.fr = 1;
			img.cnt_re = ft_atof(av[2]);
			img.cnt_im = ft_atof(av[3]);
			ft_fractol(img);
			return (0);
		}
	}
	return (ft_putendl_fd("usage: [mandelbrot]\n\
	[julia] [re_num] (0.0) [im_num] (0.0)", 2), 1);
}
