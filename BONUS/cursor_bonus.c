/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:22:50 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/26 10:02:31 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_texture(int error, t_fdf *fdf)
{
	if (error >= 1)
		mlx_delete_texture(fdf->cursor.zoom.texture);
	if (error >= 2)
		mlx_delete_texture(fdf->cursor.z_scale.texture);
	if (error >= 3)
		mlx_delete_texture(fdf->cursor.x_translate.texture);
	if (error >= 4)
		mlx_delete_texture(fdf->cursor.y_translate.texture);
	if (error >= 5)
		mlx_delete_texture(fdf->cursor.z_rotate.texture);
	if (error >= 6)
		mlx_delete_texture(fdf->cursor.x_rotate.texture);
	if (error >= 7)
		mlx_delete_texture(fdf->cursor.y_rotate.texture);
	if (error != 7)
		error_handle(MLX_ERROR, CREAT_CURSOR, fdf);
}

void	free_cursor(int error, t_fdf *fdf)
{
	if (error >= 1)
		mlx_destroy_cursor(fdf->cursor.zoom.cursor);
	if (error >= 2)
		mlx_destroy_cursor(fdf->cursor.z_scale.cursor);
	if (error >= 3)
		mlx_destroy_cursor(fdf->cursor.x_translate.cursor);
	if (error >= 4)
		mlx_destroy_cursor(fdf->cursor.y_translate.cursor);
	if (error >= 5)
		mlx_destroy_cursor(fdf->cursor.z_rotate.cursor);
	if (error >= 6)
		mlx_destroy_cursor(fdf->cursor.x_rotate.cursor);
	if (error >= 7)
		mlx_destroy_cursor(fdf->cursor.y_rotate.cursor);
	free_texture(7, fdf);
	if (error != 7)
		error_handle(MLX_ERROR, CREAT_CURSOR, fdf);
}

void	creat_texture(t_fdf *fdf)
{
	fdf->cursor.zoom.texture = mlx_load_png("./img/ZOOM.png");
	if (!fdf->cursor.zoom.texture)
		free_texture(0, fdf);
	fdf->cursor.z_scale.texture = mlx_load_png("./img/Z_SCALE.png");
	if (!fdf->cursor.z_scale.texture)
		free_texture(1, fdf);
	fdf->cursor.x_translate.texture = mlx_load_png("./img/X_TRANSLATE.png");
	if (!fdf->cursor.x_translate.texture)
		free_texture(2, fdf);
	fdf->cursor.y_translate.texture = mlx_load_png("./img/Y_TRANSLATE.png");
	if (!fdf->cursor.y_translate.texture)
		free_texture(3, fdf);
	fdf->cursor.z_rotate.texture = mlx_load_png("./img/Z_ROTATE.png");
	if (!fdf->cursor.z_rotate.texture)
		free_texture(4, fdf);
	fdf->cursor.x_rotate.texture = mlx_load_png("./img/X_ROTATE.png");
	if (!fdf->cursor.x_rotate.texture)
		free_texture(5, fdf);
	fdf->cursor.y_rotate.texture = mlx_load_png("./img/Y_ROTATE.png");
	if (!fdf->cursor.y_rotate.texture)
		free_texture(6, fdf);
}

void	creat_cursor(t_fdf *fdf)
{
	t_cursor	*cursor;

	cursor = &fdf->cursor;
	creat_texture(fdf);
	cursor->zoom.cursor = mlx_create_cursor(cursor->zoom.texture);
	if (!fdf->cursor.zoom.cursor)
		free_cursor(0, fdf);
	cursor->z_scale.cursor = mlx_create_cursor(cursor->z_scale.texture);
	if (!fdf->cursor.z_scale.cursor)
		free_cursor(1, fdf);
	cursor->x_translate.cursor = mlx_create_cursor(cursor->x_translate.texture);
	if (!fdf->cursor.x_translate.cursor)
		free_cursor(2, fdf);
	cursor->y_translate.cursor = mlx_create_cursor(cursor->y_translate.texture);
	if (!fdf->cursor.y_translate.cursor)
		free_cursor(3, fdf);
	cursor->z_rotate.cursor = mlx_create_cursor(cursor->z_rotate.texture);
	if (!fdf->cursor.z_rotate.cursor)
		free_cursor(4, fdf);
	cursor->x_rotate.cursor = mlx_create_cursor(cursor->x_rotate.texture);
	if (!fdf->cursor.x_rotate.cursor)
		free_cursor(5, fdf);
	cursor->y_rotate.cursor = mlx_create_cursor(cursor->y_rotate.texture);
	if (!fdf->cursor.y_rotate.cursor)
		free_cursor(6, fdf);
}
