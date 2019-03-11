/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:14:08 by myuliia           #+#    #+#             */
/*   Updated: 2019/02/16 12:14:08 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	step_calculate(t_wolf *f)
{
	f->alg->delta_dist_x = sqrt(1 + (pow(f->raydir_y, 2))
		/ (f->raydir_x * f->raydir_x));
	f->alg->delta_dist_y = sqrt(1 + (pow(f->raydir_x, 2))
		/ (f->raydir_y * f->raydir_y));
	if (f->raydir_x < 0)
	{
		f->alg->stepx = -1;
		f->alg->side_dist_x = (f->X_P - f->alg->map_x) * DDX;
	}
	else
	{
		f->alg->stepx = 1;
		f->alg->side_dist_x = (f->alg->map_x + 1.0 - f->red->x_pos) * DDX;
	}
	if (f->raydir_y < 0)
	{
		f->alg->stepy = -1;
		f->alg->side_dist_y = (f->red->y_pos - f->alg->map_y) * DDY;
	}
	else
	{
		f->alg->stepy = 1;
		f->alg->side_dist_y = (f->alg->map_y + 1.0 - f->red->y_pos) * DDY;
	}
	dda(f);
}

void	dda(t_wolf *f)
{
	int		hit;

	f->alg->side = 0;
	hit = 0;
	while (hit == 0)
	{
		if (f->alg->side_dist_x < f->alg->side_dist_y)
		{
			f->alg->side_dist_x += f->alg->delta_dist_x;
			f->alg->map_x += f->alg->stepx;
			f->alg->side = 0;
		}
		else
		{
			f->alg->side_dist_y += f->alg->delta_dist_y;
			f->alg->map_y += f->alg->stepy;
			f->alg->side = 1;
		}
		if (f->red->map[f->alg->map_x][f->alg->map_y] > 0
			&& f->red->map[f->alg->map_x][f->alg->map_y] < 9)
		{
			hit = 1;
		}
	}
}

void	ray_casting(t_wolf *f)
{
	f->x = -1;
	while (++f->x < WIDTH)
	{
		f->camx = 2 * f->x / (double)WIDTH - 1;
		f->raydir_x = f->alg->dir_x + f->alg->plane_x * f->camx;
		f->raydir_y = f->alg->dir_y + f->alg->plane_y * f->camx;
		f->alg->map_x = (int)f->red->x_pos;
		f->alg->map_y = (int)f->red->y_pos;
		if (f->red->map[f->alg->map_x][f->alg->map_y] == 9)
			f->win = 1;
		step_calculate(f);
		if (f->alg->side == 0)
			PERWD = (f->alg->map_x - f->X_P + (1 - SX) / 2) / f->raydir_x;
		else
			PERWD = (f->alg->map_y - Y_P + (1 - SY) / 2) / f->raydir_y;
		f->line_height = (int)(HEIGHT / PERWD);
		f->start = -f->line_height / 2 + HEIGHT / 2;
		if (f->start < 0)
			f->start = 0;
		f->end = f->line_height / 2 + HEIGHT / 2;
		if (f->end >= HEIGHT)
			f->end = HEIGHT - 1;
		line_draw(f->start - 1, f);
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}
