/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:07:57 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/21 10:32:11 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_map(t_map **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	*gnl_trim(int map_fd)
{
	char	*tmp;
	char	*line;

	tmp = get_next_line(map_fd);
	line = ft_strtrim(tmp, " \n");
	free(tmp);
	return (line);
}

t_map	**creat_map(t_fdf fdf)
{
	int		i;
	t_map	**map;

	i = 0;
	map = ft_calloc(sizeof(t_map *), fdf.map_height + 1);
	if (!map)
		error_handle(MALLOC_ERROR, MALLOC_MAP, NULL);
	while (i < fdf.map_height)
	{
		map[i] = ft_calloc(sizeof(t_map), fdf.map_width);
		if (!map[i])
		{
			free_map(map);
			error_handle(MALLOC_ERROR, MALLOC_MAP, NULL);
		}
		i++;
	}
	return (map);
}

void	set_bonus(t_fdf *fdf)
{
	fdf->zoom = 0.0;
	fdf->z_ratio = 1.0;
	fdf->x_translate = 0.0;
	fdf->y_translate = 0.0;
	fdf->map_type = 'i';
	fdf->rotate_type = Z_ROTATE;
	fdf->rotate_z = 0.0;
	fdf->rotate_x = 0.0;
	fdf->rotate_y = 0.0;
}

void	free_gnl(int map_fd)
{
	int		i;
	char	*gnl;

	i = 0;
	gnl = ft_calloc(1, 1);
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(map_fd);
	}
}
