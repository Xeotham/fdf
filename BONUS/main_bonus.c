/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:05:55 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/19 15:27:00 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		error_handle(OTHER_ERROR, TOO_MUCH_ARG, NULL);
	check_map(argv[1], &fdf);
	fdf.map = creat_map(fdf);
	map_set(argv[1], &fdf);
	fdf_start(fdf);
}
