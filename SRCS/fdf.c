/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:34:43 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/02 16:36:43 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_start(t_fdf fdf)
{
	int	i;
	int	j;

	i = 0;
	fdf.spec.mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	fdf.spec.img = mlx_new_image(fdf.spec.mlx, WIDTH, HEIGHT);
	if (mlx_image_to_window(fdf.spec.mlx, fdf.spec.img, 0, 0) < 0)
		exit(EXIT_FAILURE); //error
	while (i < fdf.map_height)
	{
		j = 0;
		while (j < fdf.map_length)
		{
			if (j < fdf.map_length - 1)
				draw_line(fdf.spec.img, convert_iso(fdf.map[i][j], fdf), convert_iso(fdf.map[i][j + 1], fdf));
			if (i < fdf.map_height - 1)
				draw_line(fdf.spec.img, convert_iso(fdf.map[i][j], fdf), convert_iso(fdf.map[i + 1][j], fdf));
			j++;
		}
		i++;
	}
	mlx_loop(fdf.spec.mlx);
}
