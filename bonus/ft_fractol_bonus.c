/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:42:58 by hakaraou          #+#    #+#             */
/*   Updated: 2024/03/04 13:25:21 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	ft_iter(t_data img, int x, int y)
{
	if (!img.fr)
		return (ft_mandelbrot(img, x, y));
	else if (img.fr == 1)
		return (ft_julia(img, x, y));
	else
		return (ft_burning_ship(img, x, y));
	return (0);
}

void	ft_draw(t_data img)
{
	long	pixel;
	long	iter;
	long	x;
	long	y;
	int		*addr;

	addr = (int *)img.addr;
	y = -1;
	while (++y < img.height)
	{
		x = -1;
		while (++x < img.width)
		{
			iter = ft_iter(img, x, y);
			pixel = (y * img.width) + x;
			if (iter < img.max_iter)
				addr[pixel] = (get_color(iter, img) + img.color);
			if (iter == img.max_iter)
				addr[pixel] = 0;
		}
	}
	mlx_clear_window(img.mlx, img.win);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
}

static void	get_info(t_data *img)
{
	img->max_iter = 50;
	img->height = 800;
	img->x_min = -2.0;
	img->y_min = -2.0;
	img->x_max = 2.0;
	img->y_max = 2.0;
	img->width = 800;
	img->up_do = 0;
	img->ri_li = 0;
	img->color = 0;
	img->zoom = 1;
	img->z1 = 1;
}

static void	my_mlx_win(t_data *img)
{
	img->mlx = mlx_init();
	if (!img->mlx)
		ft_error('1', *img);
	if (!img->fr)
		img->win = mlx_new_window(img->mlx, img->height, \
				img->width, "mandelbrot_bonus");
	else if (img->fr == 1)
		img->win = mlx_new_window(img->mlx, img->height, \
				img->width, "julia_bonus");
	else
		img->win = mlx_new_window(img->mlx, img->height, \
				img->width, "burning_ship_bonus");
	if (!img->win)
		ft_error('1', *img);
	img->img = mlx_new_image(img->mlx, img->height, img->width);
	if (!img->img)
		ft_error('2', *img);
	img->addr = mlx_get_data_addr(img->img, &img->pixel_bits, \
			&img->line_bytes, &img->endian);
	if (!img->addr)
		ft_error('2', *img);
}

void	ft_fractol(t_data img)
{
	get_info(&img);
	my_mlx_win(&img);
	ft_draw(img);
	mlx_key_hook(img.win, ft_key, &img);
	mlx_hook(img.win, 17, 0, ft_close1, &img);
	mlx_mouse_hook(img.win, ft_zoom, &img);
	mlx_loop(img.mlx);
}
