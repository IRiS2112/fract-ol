/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_fractol_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:51:35 by hakaraou          #+#    #+#             */
/*   Updated: 2024/03/01 13:33:24 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_mandelbrot(t_data img, int x, int y)
{
	double	z_re;
	double	z_im;
	double	temp;
	int		iter;

	img.cnt_re = img.x_min + x * ((img.x_max - img.x_min) / img.width)
		+ img.ri_li;
	img.cnt_im = -(img.y_min + y * ((img.y_max - img.y_min) / img.height))
		+ img.up_do;
	iter = -1;
	z_re = 0;
	z_im = 0;
	while (++iter < img.max_iter && z_re * z_re + z_im * z_im <= 4.0)
	{
		temp = z_re * z_re - z_im * z_im + img.cnt_re;
		z_im = 2.0 * z_re * z_im + img.cnt_im;
		z_re = temp;
	}
	return (iter);
}

int	ft_julia(t_data img, int x, int y)
{
	double	z_re;
	double	z_im;
	double	temp;
	int		iter;

	z_re = img.x_min + x * ((img.x_max - img.x_min) / img.width) + img.ri_li;
	z_im = -(img.y_min + y * (img.y_max - img.y_min) / img.height) + img.up_do;
	iter = -1;
	while (++iter < img.max_iter && z_re * z_re + z_im * z_im <= 4.0)
	{
		temp = z_re * z_re - z_im * z_im + img.cnt_re;
		z_im = 2.0 * z_re * z_im + img.cnt_im;
		z_re = temp;
	}
	return (iter);
}

int	ft_burning_ship(t_data img, int x, int y)
{
	double	z_re;
	double	z_im;
	double	temp;
	int		iter;

	img.cnt_re = img.x_min + x * ((img.x_max - img.x_min) / img.width)
		+ img.ri_li;
	img.cnt_im = img.y_min + y * ((img.y_max - img.y_min) / img.height)
		- img.up_do;
	iter = -1;
	z_re = 0;
	z_im = 0;
	while (++iter < img.max_iter && z_re * z_re + z_im * z_im <= 4.0)
	{
		temp = z_re * z_re - z_im * z_im + img.cnt_re;
		z_im = 2.0 * z_re * z_im + img.cnt_im;
		if (z_im < 0)
			z_im = -z_im;
		z_re = temp;
		if (z_re < 0)
			z_re = -z_re;
	}
	return (iter);
}
