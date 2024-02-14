/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:05:55 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/14 11:22:04 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
}
