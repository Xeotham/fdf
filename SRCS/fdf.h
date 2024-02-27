/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:04:02 by mhaouas           #+#    #+#             */
/*   Updated: 2024/02/22 18:13:12 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*============= INCLUDE ===========*/

# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

/*============= DEFINE FDF ===========*/

# define DEFAULT_COLOR 0xFFFFFFFF
# define WIDTH 1080
# define HEIGHT 720

/*============= COLOR ===========*/
# define RED "\033[31;1m"
# define RESET_COLOR "\033[0m"

/*============= STRUCT ===========*/

/*============= MAP ===========*/

typedef struct s_map
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_map;

/*============= MLX INFO ===========*/

typedef struct s_info
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_info;

/*============= CORE STRUCT ===========*/

typedef struct s_fdf
{
	t_map		**map;
	t_info		spec;
	int32_t		win_width;
	int32_t		win_height;
	int			map_width;
	int			map_height;
}				t_fdf;

/*============= LINE STRUCT ===========*/

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

/*============= ERROR ===========*/

enum			e_error_location
{
	MLX_ERROR,
	MALLOC_ERROR,
	OTHER_ERROR
};

enum			e_error_case
{
	TOO_MUCH_ARG,
	WRONG_MAP,
	WRONG_COLOR,
	FAILED_FD,
	SPLIT_ERROR,
	STRDUP_ERROR,
	MALLOC_MAP,
	INIT_FAIL,
	IMAGE_FAIL,
	IMG_2_WIN
};
/*============= PROTOTYP ===========*/

t_map			*get_map(int map_fd);
void			check_map(char *map_name, t_fdf *fdf);
void			map_set(char *map, t_fdf *fdf);
int				get_color(char *color, char **xs_all, t_fdf *fdf);
void			fdf_start(t_fdf fdf);
void			draw_line(t_fdf fdf, t_map a_point, t_map b_point);
t_map			**creat_map(t_fdf fdf);
t_map			convert_iso(t_map point, t_fdf fdf);
void			free_map(t_map **map);
void			print_line(void *img, t_map a_point, t_map b_point);
void			draw_map(t_fdf fdf);
void			key_press(mlx_key_data_t keydata, void *param);
void			make_img(t_fdf *fdf, int width, int height);
void			close_window(void *param);
void			resize_window(int32_t width, int32_t height, void *param);
char			*gnl_trim(int map_fd);
void			error_handle(int location, int type, t_fdf *fdf);
int				change_color(char **xs, char **xs_all, t_fdf *fdf);
void			free_gnl(int map_fd);

#endif