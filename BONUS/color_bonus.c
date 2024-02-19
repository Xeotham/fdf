/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:03:08 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/19 18:59:41 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	check_hexa(char *color)
{
	int	i;

	i = 0;
	if (!color)
		return (0);
	while (color[i])
	{
		if (!ft_strchr("0123456789abcdef", color[i]))
			return (0);
		i++;
	}
	return (1);
}

int	get_color(char *color, char **xs_all, t_fdf *fdf)
{
	int	color_int;
	int	i;

	i = 0;
	while (color[i++])
		color[i] = ft_tolower(color[i]);
	if (!ft_strncmp(color, "0x", 2) && ft_strlen(color) > 8
		&& check_hexa(color))
	{
		free_map(fdf->map);
		ft_free_2d_array(xs_all);
		error_handle(OTHER_ERROR, WRONG_COLOR, fdf);
	}
	color_int = ft_atoi_base("0123456789abcdef", color + 2);
	color_int = (color_int << 8) | 0xff;
	return (color_int);
}

int	change_color(char **xs, char **xs_all, t_fdf *fdf)
{
	int		color;
	char	**if_color;

	if_color = ft_split(*xs, ',');
	if (!if_color || !*if_color)
	{
		free_map(fdf->map);
		ft_free_2d_array(xs_all);
		error_handle(MALLOC_ERROR, SPLIT_ERROR, fdf);
	}
	free(*xs);
	*xs = ft_strdup(if_color[0]);
	if (!*xs)
	{
		free_map(fdf->map);
		ft_free_2d_array(xs_all);
		error_handle(MALLOC_ERROR, STRDUP_ERROR, fdf);
	}
	color = get_color(if_color[1], xs_all, fdf);
	ft_free_2d_array(if_color);
	return (color);
}
