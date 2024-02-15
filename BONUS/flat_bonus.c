/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flat_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:35:04 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/15 17:01:33 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	make_flat_map(t_fdf *fdf)
{
	set_bonus(fdf);
	fdf->map_type = 'f';
	mlx_delete_image(fdf->spec.mlx, fdf->spec.img);
	make_img(fdf, fdf->win_width, fdf->win_height);
	draw_map(fdf);
}

void	make_iso_map(t_fdf *fdf)
{
	fdf->map_type = 'i';
	reset_view(fdf);
}
