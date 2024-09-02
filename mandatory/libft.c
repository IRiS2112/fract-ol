/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:32:56 by hakaraou          #+#    #+#             */
/*   Updated: 2024/02/21 11:03:58 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (((unsigned char *)s1)[i] > ((unsigned char *)s2)[i])
			return (1);
		else if (((unsigned char *)s1)[i] < ((unsigned char *)s2)[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd == -1)
		return ;
	while (*s)
	{
		if (write(fd, s, 1) == -1)
		{
			perror("write");
			exit(1);
		}
		s++;
	}
	if (write(fd, "\n", 1) == -1)
	{
		perror("write");
		exit(1);
	}
}

static float	ft_atof2(char *av)
{
	float	c;
	float	f;
	int		i;

	c = 0;
	while ((*av != '\0') && (*av >= '0' && *av <= '9'))
	{
		c = c * 10 + (*av - '0');
		av++;
	}
	f = 0;
	i = 1;
	if (*av == '.')
	{
		av++;
		while ((*av != '\0') && (*av >= '0' && *av <= '9'))
		{
			f = f + (float)(*av - '0') / (10.0 * i);
			i *= 10;
			av++;
		}
	}
	return (c + f);
}

float	ft_atof(char *av)
{
	float	sign;

	while ((*av != '\0') && ((*av >= 9 && *av <= 13) || *av == 32))
		av++;
	sign = 1;
	if ((*av != '\0') && (*av == '+' || *av == '-'))
	{
		if (*av == '-')
			sign = sign * -1;
		av++;
	}
	return (ft_atof2(av) * sign);
}
