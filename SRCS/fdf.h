/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:04:02 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/15 16:48:30 by mhaouas          ###   ########.fr       */
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
	int			x;
	int			y;
	int			z;
	int			color;
}				t_map;

typedef struct s_info
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_info;

typedef struct s_fdf
{
	t_map		**map;
	t_info		spec;
	int32_t		win_width;
	int32_t		win_height;
	int			map_width;
	int			map_height;
}				t_fdf;

typedef struct s_line
{
	int			a;
	int			b;
	int			c;
	char		type;
	int			color;
	int32_t		win_width;
	int32_t		win_height;
}				t_line;

t_map			*get_map(int map_fd);
void			check_map(char *map_name, t_fdf *fdf);
void			map_set(int map_fd, t_fdf *fdf);
int				get_color(char *color);
void			fdf_start(t_fdf fdf);
void			draw_line(t_fdf fdf, t_map a_point, t_map b_point);
t_map			**creat_map(t_fdf fdf);
t_map			convert_iso(t_map point, t_fdf fdf);
void			free_map(t_map **map, int y);
void			print_line(void *img, t_map a_point, t_map b_point);
void			draw_map(t_fdf fdf);
void			key_press(mlx_key_data_t keydata, void *param);
void			make_img(t_fdf *fdf, int width, int height);
void			close_window(void *param);
void			resize_window(int32_t width, int32_t height, void *param);
char			*gnl_trim(int map_fd);

#endif