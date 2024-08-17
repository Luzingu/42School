/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:55:33 by aluzingu          #+#    #+#             */
/*   Updated: 2024/07/16 16:55:34 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <limits.h>
# include "mlx.h"
# include "libft.h"

# define ERR_USAGE			"Usage: ./fdf MAP_FILE"
# define ERR_MAP			"Incorrect MAP_FILE"
# define ERR_MAP_READING	"Reading error"
# define ERR_MAP_INIT		"Map initialization error"
# define ERR_FDF_INIT		"FdF initialization error"
# define ERR_CONV_TO_ARR	"Conversion to array"
# define ERR_CAMERA_INIT	"Camera initialization error"
# define HEIGHT				1080
# define WIDTH				1920
# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D
# define MENU_WIDTH			250
# define TEXT_COLOR			0xFFFFFF
# define BACKGROUND			0x222222
# define MENU_BACKGROUND	0x1E1E1E
# define KEY_PLUS			65451
# define KEY_MINUS			65453
# define KEY_ARROW_UP		65362
# define KEY_ARROW_DOWN		65364
# define KEY_ARROW_LEFT		65361
# define KEY_ARROW_RIGHT	65363
# define KEY_2				50
# define KEY_8				56
# define KEY_4				52
# define KEY_6				54
# define KEY_1				49
# define KEY_9				57
# define KEY_SPACE			32
# define KEY_ESC			65307
# define KEY_MENORQUE		44
# define KEY_MAIORQUE		46
# define KEY_I				105
# define KEY_P				112

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	cor;
	struct	s_point	*next;
}	t_point;

typedef struct s_camera
{
	int		zoom;
	double	angle_rot_x;
	double	angle_rot_y;
	double	angle_rot_z;
	float	z_divisor;
	int		x_offset;
	int		y_offset;
	char	projection;
}	t_camera;

typedef struct s_mapa
{
	int	width;
	int	height;
	int	max_value;
	int	min_value;
	t_point	*pontos;
}	t_mapa;

typedef struct s_fdf
{
	void		*root;
	void		*window;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_mapa		*mapa;
	t_camera	*camera;
}	t_fdf;

t_camera		*camera_init(t_fdf *fdf);
t_mapa			*mapa_init(int fd);
t_fdf			*fdf_init(t_mapa *mapa);
void			move(int key, t_fdf *fdf);
void			zoom(int key, t_fdf *fdf);
void			rotate(int key, t_fdf *fdf);
void			flatten(int key, t_fdf *fdf);
void			change_projection(int key, t_fdf *fdf);
int				check_extension(char *str);
void			terminate(char *s);
void			draw(t_fdf *fdf, t_mapa *mapa);
int				ft_abs_value(int value);
t_point			project_iso(t_point p, t_fdf *fdf);
t_point			get_point(int x, int y, t_mapa *mapa);
double			percent(int start, int end, int current);
void			print_menu(t_fdf *fdf);
void			free_mtrx(char **arr);
int				ft_isnumber(char *str, int base);
int				ft_atoi_base(char *str, int base);
int				get_color(t_point current, t_point pt_start,
					t_point pt_end, t_point diff);
char			*remove_new_line(char *str);

#endif
