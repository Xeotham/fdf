/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:52:52 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/08 13:38:04 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	key_press(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(param);
}

void	close_window(void *param)
{
	mlx_close_window(param);
}

void	resize_window(int32_t width, int32_t height , void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	mlx_delete_image(fdf->spec.mlx, fdf->spec.img);
	fdf->win_width = width;
	fdf->win_height = height;
	make_img(fdf, width, height);
	draw_map(*fdf);
}
