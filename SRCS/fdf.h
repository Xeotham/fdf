/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:04:02 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/02 16:36:59 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

# define DEFAULT_COLOR 0xFFFFFFFF
# define WIDTH 1080
# define HEIGHT 720
typedef struct s_map
{
	int		x;
	int		y;
	int		z;
	int		color;	
} t_map;

typedef struct s_info
{
	void	*mlx;
	void	*img;
	void	*win;
} t_info;

typedef struct s_fdf
{
	t_map	**map;
	t_info	spec;
	int		map_length;
	int		map_height;
} t_fdf;


t_map	*get_map(int map_fd);
void	check_map(char *map_name, t_fdf *fdf);
void	map_set(int map_fd, t_fdf *fdf);
int	get_color(char *color);
void	fdf_start(t_fdf fdf);
void	draw_line(void *fdf, t_map a_point, t_map b_point);
t_map	**creat_map(t_fdf fdf);
t_map    convert_iso(t_map point, t_fdf fdf);

void	print_line(void *img, t_map a_point, t_map b_point);


#endif