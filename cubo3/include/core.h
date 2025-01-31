/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebaptis <mebaptis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:06:39 by mebaptis          #+#    #+#             */
/*   Updated: 2025/01/21 15:21:22 by mebaptis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H
# include "./../../minilibx-linux/mlx.h"
# include "./../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>

# define	WIDTH 1500
# define	HEIGHT 850
# define    IMG_HEIGHT 64
# define    IMG_WIDTH 64
# define	FOV 0.66
# define	UP 119
# define	DOWN 115
# define	LEFT 97
# define	RIGHT 100
# define	LEFT_ROTATE  65363
# define	RIGHT_ROTATE 65361

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;

	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef struct free_s
{
	char *str1;
	char *str2;
	char *str3;
	char  **mtx1;
	char  **mtx2;
	char  **mtx3;
}	t_free;

typedef struct s_map
{
	int *no;
	int *so;
	int *we;
	int *ea;
	char *f;
	char *c;
	char	**map;
}	t_map;

typedef struct s_context
{
	void	*inst;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	double  dir_x;
	double  dir_y;
	double  plane_x;
	double  plane_y;
	double	pos_x;
	double	pos_y;
	double	raydir_x;
	double	raydir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int  colision;
	int  map_x;
	int  map_y;
	int step_x;
	int step_y;

	int width_img;
	int height_img;
	double move_speed;
	double rot_speed;

	t_map	map;
	t_player player;
	t_free free;
}	t_context;

void ft_exit(t_context *ctx,  char *str);
void ft_read_map(char *file, t_context *ctx);
int valid_file(char *file, char *pre_format);
int valid_rgb(char *str);
int ft_is_valid_file(char *file, char *pre_format);

int ft_cmp(char *str1, char *str2);
int numb_split(char **argv);
void ft_free_split(char **argv);
unsigned int rgb_to_hex(char *color);
void draw(t_context *ctx);
void ft_free_ctx(t_context *ctx);
void    ft_free(void **ptr);
void ft_valid_map(t_context *ctx);

void ft_exit_free(t_context *ctx, char *str_free, char *out);
void	ft_read_map_date(t_context *ctx, int map_line, int map_height, int map_width, int first_map_line, char *file);
void ft_read_data(t_context *ctx, char *line, int *map_line);
void	ft_read_file(char *file, t_context *ctx);
void 	define_player_position(t_context *ctx);
int key_press(int keycode, t_context *ctx);
void    init_ray_casting(t_context *ctx);
void ray_casting(t_context *ctx, int x);
void	my_mlx_pixel_put(t_context *data, int x, int y, int color);

#endif
