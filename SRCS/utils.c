/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:07:57 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/15 16:48:50 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map **map, int y)
{
	int	i;

	i = 0;
	while (i < y)
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
	map = ft_calloc(sizeof(t_map *), fdf.map_height);
	if (!map)
		exit(EXIT_FAILURE);
	while (i < fdf.map_height)
	{
		map[i] = ft_calloc(sizeof(t_map), fdf.map_width);
		if (!map[i])
		{
			free_map(map, i + 1);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (map);
}
