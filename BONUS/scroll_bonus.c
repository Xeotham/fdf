/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:34:20 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/14 11:18:27 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	z_up(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
		xdelta = ydelta * 0.1;
	printf("z_ratio = %f, ratio = %f, xdelta : %f\n", fdf->z_ratio, fdf->ratio, xdelta);
	fdf->z_ratio = fdf->z_ratio + xdelta;
	mlx_delete_image(fdf->spec.mlx, fdf->spec.img);
	make_img(fdf, fdf->win_width, fdf->win_height);
	draw_map(fdf);
}
void	x_translate_scroll(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;
	
	fdf = (t_fdf *)param;
	(void)xdelta;
	fdf->x_translate = fdf->x_translate + ((fdf->zoom + 1) * ydelta);
	printf("x_translate : %f, y_delta %f, ratio : %f\n", fdf->x_translate, ydelta, fdf->ratio);
	mlx_delete_image(fdf->spec.mlx, fdf->spec.img);
	make_img(fdf, fdf->win_width, fdf->win_height);
	draw_map(fdf);
}

void	y_translate_scroll(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;
	
	fdf = (t_fdf *)param;
	(void)xdelta;
	fdf->y_translate = fdf->y_translate + ((fdf->zoom + 1) * ydelta);
	printf("y_translate : %f, y_delta %f, ratio : %f\n", fdf->y_translate, ydelta, fdf->ratio);
	mlx_delete_image(fdf->spec.mlx, fdf->spec.img);
	make_img(fdf, fdf->win_width, fdf->win_height);
	draw_map(fdf);
}

void	zoom_scroll(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;
	
	fdf = (t_fdf *)param;
	xdelta = (fdf->zoom + (fdf->ratio * ydelta));
	
	printf("zoom : %f , ratio : %f , calcul : %f\n", fdf->zoom, fdf->ratio, xdelta);
	if (xdelta >= fdf->ratio)
		fdf->zoom = xdelta;
	else if (xdelta == 0)
		fdf->zoom = 0.0;
	else
		return ;
	mlx_delete_image(fdf->spec.mlx, fdf->spec.img);
	make_img(fdf, fdf->win_width, fdf->win_height);
	draw_map(fdf);
}

void	rotate_scroll(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;
	double	*true_rotate;
	
	fdf = (t_fdf *)param;
	(void) xdelta;
	if (fdf->rotate_type == Z_ROTATE)
		true_rotate = &fdf->rotate_z;
	else if (fdf->rotate_type == X_ROTATE)
		true_rotate = &fdf->rotate_x;
	else
		true_rotate = &fdf->rotate_y;
	(*true_rotate) += (ydelta * 0.15);
	mlx_delete_image(fdf->spec.mlx, fdf->spec.img);
	make_img(fdf, fdf->win_width, fdf->win_height);
	draw_map(fdf);
}
