/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:22:50 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/15 16:59:44 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	creat_texture(t_fdf *fdf)
{
	fdf->cursor.zoom.texture = mlx_load_png("./img/ZOOM.png");
	fdf->cursor.z_scale.texture = mlx_load_png("./img/Z_SCALE.png");
	fdf->cursor.x_translate.texture = mlx_load_png("./img/X_TRANSLATE.png");
	fdf->cursor.y_translate.texture = mlx_load_png("./img/Y_TRANSLATE.png");
	fdf->cursor.z_rotate.texture = mlx_load_png("./img/Z_ROTATE.png");
	fdf->cursor.x_rotate.texture = mlx_load_png("./img/X_ROTATE.png");
	fdf->cursor.y_rotate.texture = mlx_load_png("./img/Y_ROTATE.png");
	if (!fdf->cursor.z_scale.texture || !fdf->cursor.x_translate.texture
		|| !fdf->cursor.y_translate.texture || !fdf->cursor.z_rotate.texture
		|| !fdf->cursor.x_rotate.texture || !fdf->cursor.y_rotate.texture)
		exit(EXIT_FAILURE); // error
}

void	creat_cursor(t_fdf *fdf)
{
	t_cursor	*cursor;

	cursor = &fdf->cursor;
	creat_texture(fdf);
	cursor->zoom.cursor = mlx_create_cursor(cursor->zoom.texture);
	cursor->z_scale.cursor = mlx_create_cursor(cursor->z_scale.texture);
	cursor->x_translate.cursor = mlx_create_cursor(cursor->x_translate.texture);
	cursor->y_translate.cursor = mlx_create_cursor(cursor->y_translate.texture);
	cursor->z_rotate.cursor = mlx_create_cursor(cursor->z_rotate.texture);
	cursor->x_rotate.cursor = mlx_create_cursor(cursor->x_rotate.texture);
	cursor->y_rotate.cursor = mlx_create_cursor(cursor->y_rotate.texture);
}
