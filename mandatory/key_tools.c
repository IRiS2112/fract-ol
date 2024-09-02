/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:51:55 by hakaraou          #+#    #+#             */
/*   Updated: 2024/03/01 13:32:38 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(char n, t_data img)
{
	if (n == '2')
		mlx_destroy_window(img.mlx, img.win);
	exit (1);
}

int	ft_close1(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	exit(0);
}

int	ft_close(int keycode, t_data *img)
{
	if (keycode == 53)
		ft_close1(img);
	return (0);
}

int	ft_zoom(int keycode, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		img->zoom = img->zoom * 0.95;
	else if (keycode == 5)
		img->zoom = img->zoom * 1.05;
	else
		return (0);
	ft_draw(*img);
	return (0);
}

int	get_color(int iter, int fr)
{
	int	green;
	int	blue;
	int	red;

	if (fr == 0)
	{
		green = (iter * 15) % 256;
		blue = (iter * 10) % 256;
		red = (iter * 5) % 256;
	}
	else
	{
		green = (iter * 5) % 256;
		blue = (iter * 5) % 256;
		red = (iter * 15) % 256;
	}
	return ((red << 16) + (green << 8) + blue);
}
