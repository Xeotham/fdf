/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:03:08 by mhaouas           #+#    #+#             */
/*   Updated: 2024/01/29 14:42:54 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	get_color(char *color)
{
	int	color_int;
	int	i;

	i = 0;
	while (color[i++])
		color[i] = ft_tolower(color[i]);
	if (!ft_strncmp(color, "0x", 2) && ft_strlen(color) > 8
		&& check_hexa(color))
		exit(EXIT_FAILURE); //error
	color_int = ft_atoi_base("0123456789abcdef", color + 2);
	color_int = (color_int << 8) | 0xff;
	return (color_int);
}
