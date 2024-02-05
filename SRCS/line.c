/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:07:40 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/02 16:48:55 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(void *img, t_map a_point, t_map b_point)
{
	int	a;
	int	b;
	int	c;
	int	x;
	int	y;
	t_map	point_a;
	t_map	point_b;

	point_a = a_point;
	point_b = b_point;

	a = point_b.y - point_a.y;
	b = - (point_b.x - point_a.x);
	c = - (a * point_a.x) - (b * point_a.y);
	if (ft_abs(a) < ft_abs(b))
	{
		if (a_point.x > b_point.x)
		{
			point_a = b_point;
			point_b = a_point;
		}
		x = point_a.x;
		while (x < point_b.x)
		{
			y = ((-a * x) - c) / b;
			if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
				mlx_put_pixel(img, x, y, point_a.color);
			x++;
		}
	}
	else
	{
		if (a_point.y > b_point.y)
		{
			point_a = b_point;
			point_b = a_point;
		}
		y = point_a.y;
		while (y < point_b.y)
		{
			x = ((-b * y) - c) / a;
			if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
				mlx_put_pixel(img, x, y, point_a.color);
			y++;
		}
	}
}

static void	x_cartesian_equation(void *img, int a, int b, int c, t_map a_point, t_map b_point)
{
	t_map	tmp;
	int		x;
	int		y;

	if (a_point.x > b_point.x)
	{
		tmp = b_point;
		b_point = a_point;
		a_point = tmp;
	}
	x = a_point.x;
	while (x <= b_point.x)
	{
		y = (-a * x - c) / b;
		if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
			mlx_put_pixel(img, x, y, a_point.color);
		x++;
	}
}

static void	y_cartesian_equation(void *img, int a, int b, int c, t_map a_point, t_map b_point)
{
	t_map	tmp;
	int		x;
	int		y;

	if (a_point.y > b_point.y)
	{
		tmp = b_point;
		b_point = a_point;
		a_point = tmp;
	}
	y = a_point.y;
	while (y <= b_point.y)
	{
		x = ((-b * y) - c) / a;
		if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
			mlx_put_pixel(img, x, y, a_point.color);
		y++;
	}
}

void	print_line(void *img, t_map a_point, t_map b_point)
{
	int	a;
	int	b;
	int	c;

	a = b_point.y - a_point.y;
	b = - (b_point.x - a_point.x);
	c = - (a * a_point.x) - (b * a_point.y);
	if (a == 0 && b == 0)
		return ;
	if (ft_abs(b) > ft_abs(a))
		x_cartesian_equation(img, a, b, c, a_point, b_point);
	else
		y_cartesian_equation(img, a, b, c, a_point, b_point);
}
t_map    convert_iso(t_map point, t_fdf fdf)
{
    int    tmp_x;
    int    tmp_y;

    tmp_x = point.x;
    tmp_y = point.y;
    point.x = (tmp_x - tmp_y) * ((WIDTH / 2) / fdf.map_length) * cos(0.523599) + (((fdf.map_length / WIDTH) + (WIDTH / 2)) * ((WIDTH / 2) / fdf.map_length));
    point.y = (tmp_x + tmp_y) * ((HEIGHT / 2) / fdf.map_height) * sin (0.523599) - (point.z) + ((fdf.map_height / 2) * ((HEIGHT / 2) / fdf.map_height));
	return (point);
}
