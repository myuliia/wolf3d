/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:32:01 by myuliia           #+#    #+#             */
/*   Updated: 2019/02/07 15:33:32 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <fcntl.h>

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "keys.h"
# include <pthread.h>
# define WIDTH 1200
# define HEIGHT 800
# define WIDTH2 120
# define HEIGHT2 80
# define MAPWIDTH 20
# define MAPHEIGHT 20
# define GREY 0x99FFFFFF
# define RED 0xFF0000
# define BLUE 0x0000FF
# define BLUE1 0x000099
# define ORANGE 0xaf5a3a
# define YELLOW 0xcce07d
# define ABLUE 0xCC0000FF
# define ABLUE1 0xCC000099
# define AORANGE 0xCCaf5a3a
# define AYELLOW 0xCCcce07d
# define TRANS 0xFF000000
# define FLOOR 0x57431C
# define CEILING 0x989590
# define WHITE 16777215
# define RAD(p) (p * 3.1415926535) / 180
# define SIZE 2
# define X_P red->x_pos
# define Y_P f->red->y_pos
# define DDX f->alg->delta_dist_x
# define DDY f->alg->delta_dist_y
# define PERWD f->alg->perp_wall_dist
# define SX f->alg->stepx
# define SY f->alg->stepy
# define MXFTI mlx_xpm_file_to_image
# define MGDA mlx_get_data_addr
# define T text

typedef struct	s_mlx
{
	void		*img_ptr;
	char		*data;
	int			bits;
	int			size;
	int			endian;
}				t_mlx;

typedef struct	s_read
{
	int			height;
	int			width;
	int			fd;
	int			**map;
	double		x_pos;
	double		y_pos;
	double		step_x;
	double		step_y;
	int			maze_x_pos;
	int			maze_y_pos;
	int			indic_fill;
}				t_read;

typedef	struct	s_alg
{
	double		spd_move;
	double		spd_rot;
	double		raypos_x;
	double		raypos_y;
	double		dir_x;
	double		dir_y;
	double		plane_y;
	double		plane_x;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			map_x;
	int			map_y;
	int			stepx;
	int			stepy;
	int			side;
}				t_alg;

typedef struct	s_wolf
{
	t_mlx		text[14];
	t_read		*red;
	t_mlx		*w;
	t_alg		*alg;
	void		*mlx_ptr;
	void		*win_ptr;
	char		name_map;
	void		*img_ptr;
	char		*addr;
	int			bits;
	int			line_size;
	int			endian;
	void		*img_ptr2;
	char		*addr2;
	int			bits2;
	int			line_size2;
	int			endian2;
	int			line_height;
	int			color;
	double		raydir_x;
	double		raydir_y;
	int			x;
	double		camx;
	int			start;
	int			end;
	double		x_wall;
	double		f_xwall;
	double		f_ywall;
	double		cd;
	double		wgt;
	double		f_curr_x;
	double		f_curr_y;
	int			win;
	int			text_indic;
	int			sky_indic;
	int			indic_hints;
	int			indic_sky;
	int			indic_lab;
	int			indic_alpha;
	int			id;
	int			move_up;
	int			move_down;
	int			move_right;
	int			move_left;
	int			rot_right;
	int			rot_left;
	int			wall;
}				t_wolf;

t_alg			*init_alg(void);
t_read			*ft_read(char *file);
void			init_text(t_wolf *f);
void			text_help(t_wolf *f, int h, int w);
void			filling(t_wolf *f);
void			init_window(t_wolf *f, char *argv);
void			map_in_int(char **map, t_read *red);
char			*read_two(t_read *red, char *buf, char *tmp, char *line);
void			ft_valid_symbol(char *s);
void			ray_casting(t_wolf *f);
void			dda(t_wolf *f);
void			step_calculate(t_wolf *f);
void			set_id(t_wolf *f);
void			draw_all(t_wolf *f);
void			draw_alpha(t_wolf *f, int y);
void			maze_draw(t_wolf f, int x, int y, int i);
void			draw_block(int x, int y, t_wolf f);
void			line_draw(int start, t_wolf *f);
void			draw_text_wall(t_wolf *f, int start, int end, int d);
void			draw_text_floor(t_wolf *f, double dist_player,
	double dist_wall);
void			walls_draw(t_wolf f);
void			line_draw(int start, t_wolf *f);
void			hints(t_wolf *f);
void			draw_sky(t_wolf *f);
void			floor_calc(t_wolf *f);
void			rotation(t_wolf *f, double angl);
void			key_hints(int key, t_wolf *f);
void			ft_error(int n);
void			valid_borders(t_wolf *f);
void			set_position(t_wolf *f, int x, int y);
int				ft_key_hook(int key, t_wolf *f);
int				ft_key_release(int key, t_wolf *f);
int				moving(t_wolf *f);
void			moving_up(t_wolf *f);
int				destroy(void);

#endif
