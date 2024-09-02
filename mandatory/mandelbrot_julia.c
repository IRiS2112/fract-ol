/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_julia.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:18:56 by hakaraou          #+#    #+#             */
/*   Updated: 2024/03/02 18:15:01 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(t_data img, int x, int y)
{
	double	z_re;
	double	z_im;
	double	temp;
	int		iter;

	img.cnt_re = (-2.0 + x * ((2.0 - (-2.0)) / img.width)) * (img.zoom);
	img.cnt_im = -(-2.0 + y * ((2.0 - (-2.0)) / img.height)) * (img.zoom);
	z_re = 0;
	z_im = 0;
	iter = 0;
	while (iter < 150 && z_re * z_re + z_im * z_im <= 4.0)
	{
		temp = z_re * z_re - z_im * z_im + img.cnt_re;
		z_im = 2.0 * z_re * z_im + img.cnt_im;
		z_re = temp;
		iter++;
	}
	return (iter);
}

int	ft_julia(t_data img, int x, int y)
{
	double	z_re;
	double	z_im;
	double	temp;
	int		iter;

	z_re = (-2.0 + x * ((2.0 - (-2.0)) / img.width)) * (img.zoom);
	z_im = -(-2.0 + y * ((2.0 - (-2.0)) / img.height)) * (img.zoom);
	iter = 0;
	while (iter < 150 && z_re * z_re + z_im * z_im <= 4.0)
	{
		temp = z_re * z_re - z_im * z_im + img.cnt_re;
		z_im = 2.0 * z_re * z_im + img.cnt_im;
		z_re = temp;
		iter++;
	}
	return (iter);
}
