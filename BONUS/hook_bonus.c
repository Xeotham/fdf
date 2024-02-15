/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:52:52 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/15 17:00:19 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	key_press_bis(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_F && keydata.action == MLX_PRESS)
		make_flat_map(fdf);
	else if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
		make_iso_map(fdf);
	else
		mlx_scroll_hook(fdf->spec.mlx, zoom_scroll, fdf);
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(fdf->spec.mlx);
	else if (keydata.key == MLX_KEY_LEFT_ALT && keydata.action == MLX_PRESS
		&& keydata.modifier == 2)
		mlx_scroll_hook(fdf->spec.mlx, rotate_scroll, fdf);
	else if (keydata.key == MLX_KEY_LEFT_ALT && keydata.action == MLX_PRESS)
		mlx_scroll_hook(fdf->spec.mlx, x_translate_scroll, fdf);
	else if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS)
		mlx_scroll_hook(fdf->spec.mlx, z_up, fdf);
	else if (keydata.key == MLX_KEY_LEFT_CONTROL && keydata.action == MLX_PRESS)
		mlx_scroll_hook(fdf->spec.mlx, y_translate_scroll, fdf);
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		reset_view(fdf);
	else if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
		fdf->rotate_type = Z_ROTATE;
	else if (keydata.key == MLX_KEY_X && keydata.action == MLX_PRESS)
		fdf->rotate_type = X_ROTATE;
	else if (keydata.key == MLX_KEY_Y && keydata.action == MLX_PRESS)
		fdf->rotate_type = Y_ROTATE;
	else
		key_press_bis(keydata, fdf);
}

void	close_window(void *param)
{
	mlx_close_window(param);
}

void	resize_window(int32_t width, int32_t height, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	mlx_delete_image(fdf->spec.mlx, fdf->spec.img);
	fdf->win_width = width;
	fdf->win_height = height;
	make_img(fdf, width, height);
	draw_map(fdf);
}

void	reset_view(t_fdf *fdf)
{
	set_bonus(fdf);
	mlx_delete_image(fdf->spec.mlx, fdf->spec.img);
	make_img(fdf, fdf->win_width, fdf->win_height);
	draw_map(fdf);
}
