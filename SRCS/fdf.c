/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:34:43 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/19 19:51:47 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_img(t_fdf *fdf, int width, int height)
{
	fdf->spec.img = mlx_new_image(fdf->spec.mlx, width, height);
	if (!fdf->spec.img)
		error_handle(MLX_ERROR, IMAGE_FAIL, fdf);
	if (mlx_image_to_window(fdf->spec.mlx, fdf->spec.img, 0, 0) < 0)
		error_handle(MLX_ERROR, IMG_2_WIN, fdf);
}

void	fdf_start(t_fdf fdf)
{
	fdf.spec.mlx = mlx_init(fdf.win_width, fdf.win_height, "FdF", true);
	if (!fdf.spec.mlx)
		error_handle(MLX_ERROR, INIT_FAIL, &fdf);
	make_img(&fdf, fdf.win_width, fdf.win_height);
	draw_map(fdf);
	mlx_key_hook(fdf.spec.mlx, key_press, fdf.spec.mlx);
	mlx_close_hook(fdf.spec.mlx, close_window, fdf.spec.mlx);
	mlx_resize_hook(fdf.spec.mlx, resize_window, &fdf);
	mlx_loop(fdf.spec.mlx);
	mlx_delete_image(fdf.spec.mlx, fdf.spec.img);
	mlx_terminate(fdf.spec.mlx);
	free_map(fdf.map);
}
