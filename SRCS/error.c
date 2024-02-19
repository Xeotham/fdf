/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:44:58 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/19 19:23:23 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*mlx_error(int type, t_fdf *fdf)
{
	free_map(fdf->map);
	if (type == INIT_FAIL)
		return ("Failed to init MLX");
	else if (type == IMAGE_FAIL)
	{
		mlx_terminate(fdf->spec.mlx);
		return ("Failed to creat an image");
	}
	else if (type == IMG_2_WIN)
	{
		mlx_delete_image(fdf->spec.mlx, fdf->spec.img);
		mlx_terminate(fdf->spec.mlx);
		return ("Failed to put image to window");
	}
	return (NULL);
}

char	*malloc_error(int type)
{
	if (type == SPLIT_ERROR)
		return ("Failed to execute ft_split()");
	else if (type == MALLOC_MAP)
		return ("Failed to malloc the map");
	else if (type == STRDUP_ERROR)
		return ("Failed to execute ft_strdup()");
	return (NULL);
}

char	*other_error(int type)
{
	if (type == TOO_MUCH_ARG)
		return ("Too few or too much args");
	else if (type == FAILED_FD)
		return ("Failed to open the map");
	else if (type == WRONG_MAP)
		return ("Map isn't correct");
	else if (type == WRONG_COLOR)
		return ("Wrong color input");
	return (NULL);
}

void	error_handle(int location, int type, t_fdf *fdf)
{
	char	*message;

	if (location == MLX_ERROR)
		message = mlx_error(type, fdf);
	else if (location == MALLOC_ERROR)
		message = malloc_error(type);
	else
		message = other_error(type);
	ft_printf_fd(2, "%sERROR : %s.%s\n", RED, message, RESET_COLOR);
	exit(EXIT_FAILURE);
}
