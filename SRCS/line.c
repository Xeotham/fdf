/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:07:40 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/06 10:05:28 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	loop_line(void *img, t_map a_point, t_map b_point, char to_draw)
{
	int	a;
	int	b;
	int	c;
	int	x;
	int	y;
	
	a = b_point.y - a_point.y;
	b = - (b_point.x - a_point.x);
	c = - (a * a_point.x) - (b * a_point.y);
	if (to_draw == 'x')
	{
		x = a_point.x;
		while (x < b_point.x)
		{
			y = ((-a * x) - c) / b;
			if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
				mlx_put_pixel(img, x, y, a_point.color);
			x++;
		}
	}	
	else if (to_draw == 'y')
	{
		y = a_point.y;
		while (y < b_point.y)
		{
			x = ((-b * y) - c) / a;
			if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
				mlx_put_pixel(img, x, y, a_point.color);
			y++;
		}
	}
}

void	draw_line(void *img, t_map a_point, t_map b_point)
{
	int	x;
	int	y;
	int	a;
	int	b;

	a = b_point.y - a_point.y;
	b = - (b_point.x - a_point.x);
	if (ft_abs(a) < ft_abs(b))
	{
		if (a_point.x > b_point.x)
			loop_line(img, b_point, a_point, 'x');
		else
			loop_line(img, a_point, b_point, 'x');
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

t_map    convert_iso(t_map point, t_fdf fdf)
{
    float	tmp_x;
    float	tmp_y;
	float	ratio;

    tmp_x = point.x - (fdf.map_length / 2);
    tmp_y = point.y - (fdf.map_height / 2);
	ratio = (WIDTH / (fdf.map_length * 2));
    point.x = ((tmp_x - tmp_y) * ratio * cos(0.523599)) + (WIDTH / 2);
    point.y = ((tmp_x + tmp_y) * ratio * sin (0.523599) - point.z) + (HEIGHT / 2);
	return (point);
}
