/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:17:52 by hakaraou          #+#    #+#             */
/*   Updated: 2024/03/01 13:24:23 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_data
{
	double		zoom;
	float		cnt_re;
	float		cnt_im;
	void		*mlx;
	void		*img;
	void		*win;
	char		*addr;
	int			pixel_bits;
	int			line_bytes;
	int			height;
	int			endian;
	int			width;
	int			fr;
}				t_data;

void	ft_fractol(t_data img);
void	ft_draw(t_data img);

void	ft_error(char n, t_data img);
int		ft_zoom(int keycode, int x, int y, t_data *img);
int		ft_close(int keycode, t_data *img);
int		get_color(int iter, int fr);
int		ft_close1(t_data *img);

size_t	ft_strlen(char *str);
float	ft_atof(char *av);
void	ft_putendl_fd(char *s, int fd);
int		ft_strncmp(char *s1, char *s2, size_t n);

int		ft_mandelbrot(t_data img, int x, int y);
int		ft_julia(t_data img, int x, int y);

#endif