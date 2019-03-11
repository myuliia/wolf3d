/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:34:27 by myuliia           #+#    #+#             */
/*   Updated: 2019/03/08 14:34:29 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	init_text(t_wolf *f)
{
	int		h;
	int		w;

	f->T[0].img_ptr = MXFTI(f->mlx_ptr, "./pics/sky.xpm", &w, &h);
	f->T[0].data = MGDA(f->T[0].img_ptr, &f->T[0].bits,
		&f->T[0].size, &f->T[0].endian);
	f->T[1].img_ptr = MXFTI(f->mlx_ptr, "./pics/mossy.xpm", &w, &h);
	f->T[1].data = MGDA(f->T[1].img_ptr, &f->T[1].bits,
		&f->T[1].size, &f->T[1].endian);
	f->T[2].img_ptr = MXFTI(f->mlx_ptr, "./pics/light_brown.xpm", &w, &h);
	f->T[2].data = MGDA(f->T[2].img_ptr, &f->T[2].bits,
		&f->T[2].size, &f->T[2].endian);
	f->T[3].img_ptr = MXFTI(f->mlx_ptr, "./pics/eagle.xpm", &w, &h);
	f->T[3].data = MGDA(f->T[3].img_ptr, &f->T[3].bits,
		&f->T[3].size, &f->T[3].endian);
	f->T[4].img_ptr = MXFTI(f->mlx_ptr, "./pics/redbrick.xpm", &w, &h);
	f->T[4].data = MGDA(f->T[4].img_ptr, &f->T[4].bits,
		&f->T[4].size, &f->T[4].endian);
	f->T[5].img_ptr = MXFTI(f->mlx_ptr, "./pics/ceilling.xpm", &w, &h);
	f->T[5].data = MGDA(f->T[5].img_ptr, &f->T[5].bits,
		&f->T[5].size, &f->T[5].endian);
	f->T[6].img_ptr = MXFTI(f->mlx_ptr, "./pics/sand.xpm", &w, &h);
	f->T[6].data = MGDA(f->T[6].img_ptr, &f->T[6].bits,
		&f->T[6].size, &f->T[6].endian);
	text_help(f, h, w);
}

void	text_help(t_wolf *f, int h, int w)
{
	f->T[7].img_ptr = MXFTI(f->mlx_ptr, "./pics/purplestone.xpm", &w, &h);
	f->T[7].data = MGDA(f->T[7].img_ptr, &f->T[7].bits,
		&f->T[7].size, &f->T[7].endian);
	f->T[8].img_ptr = MXFTI(f->mlx_ptr, "./pics/colorstone.xpm", &w, &h);
	f->T[8].data = MGDA(f->T[8].img_ptr, &f->T[8].bits,
		&f->T[8].size, &f->T[8].endian);
	f->T[9].img_ptr = MXFTI(f->mlx_ptr, "./pics/cower.xpm", &w, &h);
	f->T[9].data = MGDA(f->T[9].img_ptr, &f->T[9].bits,
		&f->T[9].size, &f->T[9].endian);
	f->T[10].img_ptr = MXFTI(f->mlx_ptr, "./pics/wall_47.xpm", &w, &h);
	f->T[10].data = MGDA(f->T[10].img_ptr, &f->T[10].bits,
		&f->T[10].size, &f->T[10].endian);
	f->T[11].img_ptr = MXFTI(f->mlx_ptr, "./pics/greystone.xpm", &w, &h);
	f->T[11].data = MGDA(f->T[11].img_ptr, &f->T[11].bits,
		&f->T[11].size, &f->T[11].endian);
	f->T[12].img_ptr = MXFTI(f->mlx_ptr, "./pics/wall_51.xpm", &w, &h);
	f->T[12].data = MGDA(f->T[12].img_ptr, &f->T[12].bits,
		&f->T[12].size, &f->T[12].endian);
	f->T[13].img_ptr = MXFTI(f->mlx_ptr, "./pics/win.xpm", &w, &h);
	f->T[13].data = MGDA(f->T[13].img_ptr, &f->T[13].bits,
		&f->T[13].size, &f->T[13].endian);
}

void	set_pos_help(t_wolf *f)
{
	if (f->red->map[f->red->width / 2][f->red->height / 2] == 0)
	{
		f->red->x_pos = (f->red->width / 2) + 0.5;
		f->red->y_pos = (f->red->height / 2) + 0.5;
		return ;
	}
	else if (f->red->map[f->red->width / 2][f->red->height / 3] == 0)
	{
		f->red->x_pos = (f->red->width / 2) + 0.5;
		f->red->y_pos = (f->red->height / 3) + 0.5;
		return ;
	}
}

void	moving_up(t_wolf *f)
{
	if (f->move_up == 1)
	{
		if (f->red->map[(int)(f->X_P + f->alg->dir_x
			* 0.9)][(int)(Y_P)] == 0 ||
			f->red->map[(int)(f->X_P + f->alg->dir_x
			* 0.9)][(int)(Y_P)] == 9)
			f->X_P += f->alg->dir_x * f->alg->spd_move;
		if (f->red->map[(int)(f->X_P)][(int)(Y_P
			+ f->alg->dir_y * 0.9)] == 0 ||
			f->red->map[(int)(f->X_P)][(int)(Y_P
			+ f->alg->dir_y * 0.9)] == 9)
			Y_P += f->alg->dir_y * f->alg->spd_move;
	}
}

int		moving(t_wolf *f)
{
	moving_up(f);
	if (f->move_down == 1)
	{
		if (f->red->map[(int)(f->X_P -
			f->alg->dir_x * 0.9)][(int)(Y_P)] == 0 ||
			f->red->map[(int)(f->X_P -
			f->alg->dir_x * 0.9)][(int)(Y_P)] == 9)
			f->X_P -= f->alg->dir_x * f->alg->spd_move;
		if (f->red->map[(int)(f->X_P)][(int)(Y_P
			- f->alg->dir_y * 0.9)] == 0 ||
			f->red->map[(int)(f->X_P)][(int)(Y_P
			- f->alg->dir_y * 0.9)] == 9)
			Y_P -= f->alg->dir_y * f->alg->spd_move;
	}
	if (f->rot_left == 1)
		rotation(f, f->alg->spd_rot);
	else if (f->rot_right == 1)
		rotation(f, -f->alg->spd_rot);
	draw_all(f);
	return (0);
}
