/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:42:44 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/02 14:02:32 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(void)
{
	t_fdf	fdf;
	t_map	test1 = {5, 510, 1, 0x0000ffff};
	t_map	test2 = {10, 10, 1, -1};
	fdf.spec.mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	fdf.spec.img = mlx_new_image(fdf.spec.mlx, WIDTH, HEIGHT);
	if (mlx_image_to_window(fdf.spec.mlx, fdf.spec.img, 0, 0) < 0)
		exit(1);
	draw_line(fdf.spec.img, test1, test2);
	mlx_loop_hook(fdf.spec.mlx, ft_hook, fdf.spec.mlx);
	mlx_loop(fdf.spec.mlx);
}
