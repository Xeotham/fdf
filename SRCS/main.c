/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:05:55 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/02 14:42:38 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		map_fd;
	t_fdf	fdf;

	if (argc != 2)
		return (1);
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
		exit(EXIT_FAILURE); //futur error message
	check_map(argv[1], &fdf);
	fdf.map = creat_map(fdf);
	map_set(map_fd, &fdf);
	fdf_start(fdf);
	/*fdf.spec.mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	fdf.spec.img = mlx_new_image(fdf.spec.mlx, WIDTH, HEIGHT);
	if (mlx_image_to_window(fdf.spec.mlx, fdf.spec.img, 0, 0) < 0)
		exit(EXIT_FAILURE); //error
	t_map	test1 = {500, 500, 1, 0x0000ffff};
	t_map	test2 = {000, 500, 1, -1};
	draw_line(fdf.spec.img, test1, test2);
	mlx_loop(fdf.spec.mlx);*/
}
