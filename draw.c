/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:05:37 by myuliia           #+#    #+#             */
/*   Updated: 2019/02/15 14:05:38 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	draw_all(t_wolf *f)
{
	if (f->red->indic_fill != 1)
	{
		filling(f);
		set_position(f, 0, 0);
	}
	ray_casting(f);
	if (f->indic_hints == 1)
	{
		maze_draw(*f, 0, 0, -1);
		hints(f);
	}
	if (f->sky_indic == 2)
		draw_sky(f);
	f->red->indic_fill = 1;
	if (f->win == 1)
		mlx_put_image_to_window(f->mlx_ptr, f->win_ptr,
			f->text[13].img_ptr, 0, 0);
}

void	draw_alpha(t_wolf *f, int y)
{
	if (f->alg->side == 1 && f->raydir_y > 0)
		f->color = ABLUE;
	else if (f->alg->side == 0 && f->raydir_x < 0)
		f->color = AORANGE;
	else if (f->alg->side == 0 && f->raydir_x > 0)
		f->color = ABLUE1;
	else
		f->color = AYELLOW;
	*(int *)(f->addr + 4 * WIDTH * y + f->x * 4) = f->color;
}

void	set_id(t_wolf *f)
{
	f->id = f->red->map[f->alg->map_x][f->alg->map_y];
	if (f->id == 1)
	{
		if (f->alg->side == 1 && f->raydir_y > 0)
			f->id = 1;
		else if (f->alg->side == 0 && f->raydir_x < 0)
			f->id = 10;
		else if (f->alg->side == 0 && f->raydir_x > 0)
			f->id = 11;
		else
			f->id = 12;
	}
}

void	draw_sky(t_wolf *f)
{
	int		xt;
	int		yt;

	xt = 0;
	while (xt < WIDTH)
	{
		yt = 0;
		while (yt < HEIGHT / 2)
		{
			ft_memcpy(f->addr + 4 * WIDTH * yt + xt * 4,
					&f->text[0].data[yt % 512 * f->text[0].size +
					xt % 512 * f->text[0].bits / 8], sizeof(int));
			yt++;
		}
		xt++;
	}
}

void	filling(t_wolf *f)
{
	f->alg->dir_x = -1;
	f->alg->dir_y = 0;
	f->alg->plane_x = 0;
	f->alg->plane_y = 0.66;
	f->alg->spd_rot = 0.05;
	f->alg->spd_move = 0.05;
	f->move_up = 0;
	f->move_down = 0;
	f->move_right = 0;
	f->move_left = 0;
	f->indic_hints = 1;
	f->sky_indic = 0;
	f->red->indic_fill = 1;
	f->text_indic = 0;
	f->win = 0;
}
