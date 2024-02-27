/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:05:55 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/22 18:10:54 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		error_handle(OTHER_ERROR, TOO_MUCH_ARG, NULL);
	check_map(argv[1], &fdf);
	fdf.map = creat_map(fdf);
	fdf.win_height = HEIGHT;
	fdf.win_width = WIDTH;
	map_set(argv[1], &fdf);
	fdf_start(fdf);
}
