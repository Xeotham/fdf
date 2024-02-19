/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:07:40 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/19 10:42:19 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	loop_line(void *img, t_map a_point, t_map b_point, t_line info)
{
	int	x;
	int	y;

	if (info.type == 'x')
	{
		x = a_point.x;
		while (x < b_point.x)
		{
			y = ((-info.a * x) - info.c) / info.b;
			if (x > 0 && y > 0 && x < info.win_width && y < info.win_height)
				mlx_put_pixel(img, x, y, info.color);
			x++;
		}
	}
	else if (info.type == 'y')
	{
		y = a_point.y;
		while (y < b_point.y)
		{
			x = ((-info.b * y) - info.c) / info.a;
			if (x > 0 && y > 0 && x < info.win_width && y < info.win_height)
				mlx_put_pixel(img, x, y, info.color);
			y++;
		}
	}
}

void	draw_line(t_fdf fdf, t_map a_point, t_map b_point)
{
	t_line	info;

	info.a = b_point.y - a_point.y;
	info.b = -(b_point.x - a_point.x);
	info.c = -(info.a * a_point.x) - (info.b * a_point.y);
	info.color = b_point.color;
	info.win_height = fdf.win_height;
	info.win_width = fdf.win_width;
	if (ft_abs(info.a) < ft_abs(info.b))
	{
		info.type = 'x';
		if (a_point.x > b_point.x)
			loop_line(fdf.spec.img, b_point, a_point, info);
		else
			loop_line(fdf.spec.img, a_point, b_point, info);
	}
	else
	{
		info.type = 'y';
		if (a_point.y > b_point.y)
			loop_line(fdf.spec.img, b_point, a_point, info);
		else
			loop_line(fdf.spec.img, a_point, b_point, info);
	}
}

t_map	convert_iso(t_map point, t_fdf *fdf)
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;

	tmp_x = point.x - (fdf->map_width / 2);
	tmp_y = point.y - (fdf->map_height / 2);
	tmp_z = point.z * fdf->z_ratio;
	if ((fdf->map_width >= fdf->map_height))
		fdf->ratio = (fdf->win_width) / ((fdf->map_width * 2));
	else
		fdf->ratio = ((fdf->win_height) / (fdf->map_height));
	apply_rotate(&tmp_x, &tmp_y, &tmp_z, fdf);
	tmp_x = tmp_x * (fdf->ratio + fdf->zoom);
	tmp_y = tmp_y * (fdf->ratio + fdf->zoom);
	if (fdf->map_type == 'i')
	{
		tmp_x = tmp_x * cos(0.523599);
		tmp_y = (tmp_y * sin(0.523599)) - tmp_z;
	}
	apply_translation(&tmp_x, &tmp_y, fdf);
	point.x = tmp_x;
	point.y = tmp_y;
	return (point);
}

void	draw_map(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map_height)
	{
		j = 0;
		while (j < fdf->map_width)
		{
			if (j < fdf->map_width - 1)
				draw_line(*fdf, convert_iso(fdf->map[i][j], fdf),
					convert_iso(fdf->map[i][j + 1], fdf));
			if (i < fdf->map_height - 1)
				draw_line(*fdf, convert_iso(fdf->map[i][j], fdf),
					convert_iso(fdf->map[i + 1][j], fdf));
			j++;
		}
		i++;
	}
}
