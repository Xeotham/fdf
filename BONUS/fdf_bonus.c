/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:34:43 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/19 15:27:16 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	mlx_to_do(t_fdf fdf)
{
	mlx_scroll_hook(fdf.spec.mlx, zoom_scroll, &fdf);
	mlx_key_hook(fdf.spec.mlx, key_press, &fdf);
	mlx_close_hook(fdf.spec.mlx, close_window, fdf.spec.mlx);
	mlx_resize_hook(fdf.spec.mlx, resize_window, &fdf);
}

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
	fdf.spec.img = mlx_new_image(fdf.spec.mlx, fdf.win_width, fdf.win_height);
	creat_cursor(&fdf);
	set_bonus(&fdf);
	draw_map(&fdf);
	mlx_to_do(fdf);
	mlx_loop(fdf.spec.mlx);
	mlx_terminate(fdf.spec.mlx);
	free_map(fdf.map);
}
