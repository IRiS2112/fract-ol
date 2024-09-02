/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:23:10 by hakaraou          #+#    #+#             */
/*   Updated: 2024/03/01 13:31:45 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_iter(t_data img, int x, int y)
{
	int	iter;

	if (!img.fr)
		iter = ft_mandelbrot(img, x, y);
	else
		iter = ft_julia(img, x, y);
	return (iter);
}

void	ft_draw(t_data img)
{
	int	*addr;
	int	pixel;
	int	iter;
	int	x;
	int	y;

	addr = (int *)img.addr;
	y = -1;
	while (++y < img.height)
	{
		x = -1;
		while (++x < img.width)
		{
			iter = ft_iter(img, x, y);
			pixel = (y * img.width) + x;
			if (iter < 150)
				addr[pixel] = get_color(iter, img.fr);
			if (iter == 150)
				addr[pixel] = 0;
		}
	}
	mlx_clear_window(img.mlx, img.win);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
}

static void	get_info(t_data *img)
{
	img->height = 800;
	img->width = 800;
	img->zoom = 1;
}

static void	my_mlx_win(t_data *img)
{
	img->mlx = mlx_init();
	if (!img->mlx)
		ft_error('1', *img);
	if (!img->fr)
		img->win = mlx_new_window(img->mlx,
				img->height, img->width, "mandelbrot");
	else
		img->win = mlx_new_window(img->mlx, img->height, img->width, "julia");
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
	mlx_key_hook(img.win, ft_close, &img);
	mlx_hook(img.win, 17, 0, ft_close1, &img);
	mlx_mouse_hook(img.win, ft_zoom, &img);
	mlx_loop(img.mlx);
}
