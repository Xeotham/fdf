/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:12:11 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/19 15:47:29 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	check_map_loop(t_fdf *fdf, int map_fd, char *line, int *line_count)
{
	while (line)
	{
		(*line_count)++;
		free(line);
		line = gnl_trim(map_fd);
		if (!line)
			break ;
		if (ft_count_word(line, ' ') != fdf->map_width)
		{
			free(line);
			error_handle(OTHER_ERROR, WRONG_MAP, fdf);
		}
	}
}

void	check_map(char *map_name, t_fdf *fdf)
{
	int		map_fd;
	int		line_count;
	char	*line;

	line_count = 0;
	map_fd = open(map_name, O_RDONLY);
	if (map_fd < 0)
		error_handle(OTHER_ERROR, FAILED_FD, NULL);
	line = gnl_trim(map_fd);
	if (!line)
		error_handle(OTHER_ERROR, WRONG_MAP, NULL);
	fdf->map_width = ft_count_word(line, ' ');
	check_map_loop(fdf, map_fd, line, &line_count);
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
				free_map(fdf->map);
				error_handle(OTHER_ERROR, WRONG_MAP, fdf);
			}
		}
		i++;
	}
}

void	set_args(int y, char **xs, t_fdf *fdf)
{
	int		i;
	int		color;

	i = 0;
	while (i < fdf->map_width)
	{
		color = DEFAULT_COLOR;
		if (ft_count_word(xs[i], ',') == 2)
			color = change_color(&xs[i], xs, fdf);
		fdf->map[y][i].y = y;
		fdf->map[y][i].x = i;
		fdf->map[y][i].z = ft_atoi(xs[i]);
		fdf->map[y][i].color = color;
		i++;
	}
}

void	map_set(char *map, t_fdf *fdf)
{
	int		i;
	int		map_fd;
	char	*line;
	char	**args;

	i = 0;
	fdf->win_height = HEIGHT;
	fdf->win_width = WIDTH;
	map_fd = open(map, O_RDONLY);
	if (map_fd == -1)
		error_handle(OTHER_ERROR, FAILED_FD, fdf);
	while (i < fdf->map_height)
	{
		line = gnl_trim(map_fd);
		args = ft_split(line, ' ');
		if (!args || !*args)
			error_handle(MALLOC_ERROR, SPLIT_ERROR, fdf);
		check_z(args, fdf);
		set_args(i, args, fdf);
		free(line);
		ft_free_2d_array(args);
		i++;
	}
	close(map_fd);
}
