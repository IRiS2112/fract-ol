/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tools_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:48:27 by hakaraou          #+#    #+#             */
/*   Updated: 2024/03/04 13:24:55 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_error(char n, t_data img)
{
	if (n == '2')
		mlx_destroy_window(img.mlx, img.win);
	exit (1);
}

int	ft_key(int keycode, t_data *img)
{
	if (keycode == 78)
		img->max_iter -= 10;
	if (keycode == 69 && img->max_iter < 120)
		img->max_iter += 10;
	if (keycode == 53)
		ft_close1(img);
	if (keycode == 123)
		img->ri_li -= 0.05 * img->z1;
	if (keycode == 124)
		img->ri_li += 0.05 * img->z1;
	if (keycode == 125)
		img->up_do -= 0.05 * img->z1;
	if (keycode == 126)
		img->up_do += 0.05 * img->z1;
	if (keycode == 48)
		img->color += 10000;
	if (keycode == 123 || keycode == 124
		|| keycode == 125 || keycode == 126
		|| keycode == 48 || keycode == 78 || keycode == 69)
		ft_draw(*img);
	return (0);
}

int	ft_close1(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	exit(0);
}

int	ft_zoom(int keycode, int x, int y, t_data *img)
{
	double	mx;
	double	my;

	if (y >= 0 && x >= 0 && (keycode == 5 || keycode == 4))
	{
		mx = img->x_min + x * ((img->x_max - img->x_min) / img->width);
		my = img->y_min + y * ((img->y_max - img->y_min) / img->height);
		if (keycode == 4)
		{
			img->zoom = 0.95;
			img->z1 *= 0.95;
		}
		else if (keycode == 5)
		{
			img->zoom = 1.05;
			img->z1 *= 1.05;
		}
		img->x_min = mx + img->zoom * (img->x_min - mx);
		img->x_max = mx + img->zoom * (img->x_max - mx);
		img->y_min = my + img->zoom * (img->y_min - my);
		img->y_max = my + img->zoom * (img->y_max - my);
		ft_draw(*img);
	}
	return (0);
}
