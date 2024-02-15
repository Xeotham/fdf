/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:16:04 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/15 17:01:11 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_point(double *a, double *b, double rotate)
{
	double	tmp_a;
	double	tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	if (!rotate)
		return ;
	*a = (tmp_a * cos(rotate)) - (tmp_b * sin(rotate));
	*b = (tmp_a * sin(rotate)) + (tmp_b * cos(rotate));
}

void	apply_rotate(double *x, double *y, double *z, t_fdf *fdf)
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;

	rotate_point(x, y, fdf->rotate_z);
	rotate_point(z, y, fdf->rotate_x);
	rotate_point(z, x, fdf->rotate_y);
	tmp_x = *x;
	tmp_y = *y;
	tmp_z = *z;
	if (fdf->map_type == 'i')
	{
		*x = tmp_x - tmp_y;
		*y = (tmp_x + tmp_y) / 2 - tmp_z;
	}
}

void	apply_translation(double *x, double *y, t_fdf *fdf)
{
	(*x) += (fdf->win_width / 2) + fdf->x_translate;
	(*y) += (fdf->win_height / 2) + fdf->y_translate;
}
