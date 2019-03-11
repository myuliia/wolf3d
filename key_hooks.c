/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:49:09 by myuliia           #+#    #+#             */
/*   Updated: 2019/02/08 20:49:10 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	rotation(t_wolf *f, double angl)
{
	double	tmp_d;
	double	tmp_pl;

	tmp_d = f->alg->dir_x;
	f->alg->dir_x = f->alg->dir_x * cos(angl)
	- f->alg->dir_y * sin(angl);
	f->alg->dir_y = tmp_d * sin(angl)
	+ f->alg->dir_y * cos(angl);
	tmp_pl = f->alg->plane_x;
	f->alg->plane_x = f->alg->plane_x * cos(angl)
	- f->alg->plane_y * sin(angl);
	f->alg->plane_y = tmp_pl * sin(angl)
	+ f->alg->plane_y * cos(angl);
}

void	key_hints_help(int key, t_wolf *f)
{
	if (key == KEY_P)
	{
		if (f->indic_alpha == 0)
		{
			f->alg->spd_rot = 0.01;
			f->alg->spd_move = 0.01;
			f->indic_alpha = 1;
		}
		else
		{
			f->indic_alpha = 0;
			f->alg->spd_rot = 0.05;
			f->alg->spd_move = 0.05;
		}
	}
}

void	key_hints(int key, t_wolf *f)
{
	if (key == KEY_H)
	{
		if (f->indic_hints == 1)
			f->indic_hints = 0;
		else
			f->indic_hints = 1;
	}
	if (key == KEY_Y)
	{
		if (f->sky_indic == 2)
			f->sky_indic = 0;
		else
			f->sky_indic = 2;
	}
	if (key == KEY_T)
	{
		if (f->text_indic == 0)
			f->text_indic = 1;
		else
			f->text_indic = 0;
	}
	key_hints_help(key, f);
}

int		ft_key_release(int key, t_wolf *f)
{
	if (key == 257 || key == 258)
	{
		f->alg->spd_move = 0.05;
		if (f->indic_alpha == 1)
			f->alg->spd_move = 0.01;
	}
	if (key == KEY_W || key == 126)
		f->move_up = 0;
	if (key == KEY_S || key == 125)
		f->move_down = 0;
	if (key == 124 || key == KEY_D)
		f->rot_right = 0;
	if (key == 123 || key == KEY_A)
		f->rot_left = 0;
	return (0);
}

int		ft_key_hook(int key, t_wolf *f)
{
	if (key == ESC)
	{
		system("killall afplay");
		exit(0);
	}
	if (key == KEY_W || key == 126)
		f->move_up = 1;
	if (key == KEY_S || key == 125)
		f->move_down = 1;
	if (key == 124 || key == KEY_D)
		f->rot_right = 1;
	if (key == 123 || key == KEY_A)
		f->rot_left = 1;
	if (key == KEY_H || key == KEY_T || key == KEY_Y || key == KEY_P)
		key_hints(key, f);
	if (key == 257 || key == 258)
	{
		f->alg->spd_move = 0.11;
		if (f->indic_alpha == 1)
			f->alg->spd_move = 0.05;
	}
	if (key == 36)
		f->red->indic_fill = 2;
	return (0);
}
