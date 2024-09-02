/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:19:56 by hakaraou          #+#    #+#             */
/*   Updated: 2024/03/01 15:19:56 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	get_color(int iter, t_data img)
{
	int	green;
	int	blue;
	int	red;

	if (!img.fr)
	{
		green = (iter * 5) % 256;
		blue = (iter * 15) % 256;
		red = (iter * 3) % 256;
	}
	else if (img.fr == 1)
	{
		green = (iter * 5) % 256;
		blue = (iter * 15) % 256;
		red = (iter * 10) % 256;
	}
	else
	{
		green = (iter * 4) % 256;
		blue = (iter * 1) % 256;
		red = (iter * 15) % 256;
	}
	return ((red << 16) + (green << 8) + blue);
}
