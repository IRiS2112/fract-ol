/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:55:49 by hakaraou          #+#    #+#             */
/*   Updated: 2024/03/04 13:22:06 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_data
{
	double		cnt_re;
	double		cnt_im;
	double		up_do;
	double		ri_li;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		zoom;
	double		z1;
	void		*mlx;
	void		*img;
	void		*win;
	char		*addr;
	int			pixel_bits;
	int			line_bytes;
	int			max_iter;
	int			height;
	int			endian;
	int			width;
	int			color;
	int			fr;
}				t_data;

int		ft_burning_ship(t_data img, int x, int y);
int		ft_mandelbrot(t_data img, int x, int y);
int		ft_julia(t_data img, int x, int y);

int		get_color(int iter, t_data img);

void	ft_fractol(t_data img);
void	ft_draw(t_data img);

void	ft_error(char n, t_data img);
int		ft_zoom(int keycode, int x, int y, t_data *img);
int		ft_key(int keycode, t_data *img);
int		ft_close1(t_data *img);

size_t	ft_strlen(char *str);
float	ft_atof(char *av);
void	ft_putendl_fd(char *s, int fd);
int		ft_strncmp(char *s1, char *s2, size_t n);

#endif