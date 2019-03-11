/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:20:27 by myuliia           #+#    #+#             */
/*   Updated: 2019/03/06 18:20:28 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	floor_calc(t_wolf *f)
{
	if (f->alg->side == 0 && f->raydir_x > 0)
	{
		f->f_xwall = f->alg->map_x;
		f->f_ywall = f->alg->map_y + f->x_wall;
	}
	else if (f->alg->side == 0 && f->raydir_x < 0)
	{
		f->f_xwall = f->alg->map_x + 1.0;
		f->f_ywall = f->alg->map_y + f->x_wall;
	}
	else if (f->alg->side == 1 && f->raydir_y > 0)
	{
		f->f_xwall = f->alg->map_x + f->x_wall;
		f->f_ywall = f->alg->map_y;
	}
	else
	{
		f->f_xwall = f->alg->map_x + f->x_wall;
		f->f_ywall = f->alg->map_y + 1.0;
	}
}

void	draw_text_floor(t_wolf *f, double dist_player, double dist_wall)
{
	int		floor_xtex;
	int		floor_ytex;
	int		y;

	floor_calc(f);
	y = f->end - 1;
	while (++y < HEIGHT)
	{
		f->cd = HEIGHT / (2.0 * y - HEIGHT);
		f->wgt = (f->cd - dist_player) / (dist_wall - dist_player);
		f->f_curr_x = f->wgt * f->f_xwall + (1.0 - f->wgt) * f->red->x_pos;
		f->f_curr_y = f->wgt * f->f_ywall + (1.0 - f->wgt) * f->red->y_pos;
		floor_xtex = (int)(f->f_curr_x * 512) % 512;
		floor_ytex = (int)(f->f_curr_y * 512) % 512;
		ft_memcpy(f->addr + 4 * WIDTH * y + f->x * 4,
			&f->text[6].data[4 * (512 * floor_ytex + floor_xtex)], sizeof(int));
		if (f->sky_indic != 2)
		{
			ft_memcpy(f->addr + 4 * WIDTH * (HEIGHT - y) + f->x * 4,
				&f->text[5].data[4 * (512 * floor_ytex + floor_xtex)],
				sizeof(int));
		}
	}
}

void	draw_text_wall(t_wolf *f, int start, int end, int d)
{
	int		x_text;
	int		y_text;
	int		y;
	int		color;

	set_id(f);
	if (f->alg->side == 0)
		f->x_wall = f->red->y_pos + PERWD * f->raydir_y;
	else
		f->x_wall = f->red->x_pos + PERWD * f->raydir_x;
	f->x_wall -= (int)f->x_wall;
	x_text = (int)(f->x_wall * 64.0);
	if (f->alg->side == 0 && f->raydir_x > 0)
		x_text = 64 - x_text - 1;
	if (f->alg->side == 1 && f->raydir_y < 0)
		x_text = 64 - x_text - 1;
	y = start - 1;
	while (++y < (end + 1))
	{
		d = y * 256 - HEIGHT * 128 + f->line_height * 128;
		y_text = ((d * 64) / f->line_height) / 256;
		ft_memcpy(f->addr + 4 * WIDTH * y + f->x * 4,
					&f->text[f->id].data[y_text % 64 * f->text[f->id].size +
					x_text % 64 * f->text[f->id].bits / 8], sizeof(int));
	}
}

int		line_draw_help(t_wolf *f, int y)
{
	while (++y <= f->end)
	{
		if (f->text_indic != 1 && f->indic_alpha != 1)
		{
			if (f->alg->side == 1 && f->raydir_y > 0)
				f->color = BLUE;
			else if (f->alg->side == 0 && f->raydir_x < 0)
				f->color = ORANGE;
			else if (f->alg->side == 0 && f->raydir_x > 0)
				f->color = BLUE1;
			else
				f->color = YELLOW;
			*(int *)(f->addr + 4 * WIDTH * y + f->x * 4) = f->color;
			f->wall = y;
		}
		if (f->indic_alpha == 1 && f->text_indic != 1)
			draw_alpha(f, y);
	}
	y--;
	return (y);
}

void	line_draw(int start, t_wolf *f)
{
	int y;

	y = -1;
	if (f->text_indic == 1)
	{
		draw_text_wall(f, start, f->end, 0);
		draw_text_floor(f, 0.0, PERWD);
	}
	if (f->x < WIDTH && y < HEIGHT)
	{
		while (++y < start)
		{
			if (f->text_indic == 0 && f->sky_indic != 2)
				*(int *)(f->addr + 4 * WIDTH * y + f->x * 4) = CEILING;
		}
		y--;
		y = line_draw_help(f, y);
		while (++y < HEIGHT)
		{
			if (f->text_indic != 1)
			{
				*(int *)(f->addr + 4 * WIDTH * y + f->x * 4) = FLOOR;
			}
		}
	}
}
