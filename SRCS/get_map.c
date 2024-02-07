/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:12:11 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/05 21:19:23 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_map(char *map_name, t_fdf *fdf)
{
	int		map_fd;
	int		line_count;
	char	*line;

	line_count = 0;
	map_fd = open(map_name, O_RDONLY);
	line = ft_strtrim(get_next_line(map_fd), " \n");
	if (!line)
		exit(EXIT_FAILURE) ; //error
	fdf->map_length = ft_count_word(line, ' ');
	while (line)
	{
		free(line);
		line = ft_strtrim(get_next_line(map_fd), " \n");
		if (!line)
			break ;
		if (ft_count_word(line, ' ') != fdf->map_length)
		{
			free(line);
			exit(EXIT_FAILURE); //error
		}	
		line_count++;
	}
	free(line);
	close(map_fd);
	fdf->map_height = line_count;
}

void	check_z(char **line, t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (j != 0 && line[i][j] == ',')
				break ;
			if (((line[i][j] == '-' || line[i][j] == '+')
				&& ft_isdigit(line[i][j + 1])) || ft_isdigit(line[i][j]))
				j++;
			else
			{
				free_map(fdf->map, fdf->map_height);
				exit(EXIT_FAILURE); //error
			}
		}
		i++;
	}
}

void	set_args(int y, char **xs, t_fdf *fdf)
{
	int		i;
	int		color;
	char	**if_color;

	i = 0;
	while (i < fdf->map_length)
	{
		color = DEFAULT_COLOR;
		if (ft_count_word(xs[i], ',') == 2)
		{
			if_color = ft_split(xs[i], ',');
			free(xs[i]);
			xs[i] = if_color[0];
			color = get_color(if_color[1]);
			free(if_color[1]);
		}
		fdf->map[y][i].y = y;
		fdf->map[y][i].x = i;
		fdf->map[y][i].z = ft_atoi(xs[i]);
		fdf->map[y][i].color = color;
		i++;
	}
}

void	map_set(int map_fd, t_fdf *fdf)
{
	int		i;
	char	*line;
	char	**args;

	i = 0;
	while (i < fdf->map_height)
	{
		line = ft_strtrim(get_next_line(map_fd), " \n");
		args = ft_split(line, ' ');
		check_z(args, fdf);
		set_args(i, args, fdf);
		free(line);
		ft_free_2d_array(args);
		i++;
	}
	close(map_fd);
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
		map[i] = ft_calloc(sizeof(t_map), fdf.map_length);
		if (!map[i])
		{
			free_map(map, i + 1);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (map);
}
