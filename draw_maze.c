/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_maze.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 21:23:33 by myuliia           #+#    #+#             */
/*   Updated: 2019/02/08 21:23:34 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	background(t_wolf f)
{
	int x;
	int y;

	y = -1;
	while (++y != 800)
	{
		x = -1;
		while (++x != 175)
		{
			*(int *)(f.addr2 + 4 * WIDTH * y + x * 4) = 0x99422f23;
		}
	}
}

void	draw_block(int x, int y, t_wolf f)
{
	int		sx;
	int		sy;

	x = x + 20;
	y = y + 35;
	sx = x - f.red->step_x;
	while (sx < x)
	{
		sy = y - f.red->step_y;
		while (sy < y)
		{
			*(int *)(f.addr2 + 4 * WIDTH * sy + sx * 4) = GREY;
			sy++;
		}
		sx++;
	}
}

void	maze_draw(t_wolf f, int x, int y, int i)
{
	int		j;

	background(f);
	f.red->step_x = (WIDTH / 8) / f.red->width;
	f.red->step_y = (HEIGHT / 5) / f.red->height;
	while (++i < f.red->height)
	{
		j = -1;
		while (++j < f.red->width)
		{
			if (f.red->map[i][j] != 0 && f.red->map[i][j] != 9)
			{
				x = (j + 1) * f.red->step_x;
				y = (i + 1) * f.red->step_y;
				draw_block(x, y, f);
			}
		}
	}
	mlx_put_image_to_window(f.mlx_ptr, f.win_ptr, f.img_ptr2, 0, 0);
}

void	hints(t_wolf *f)
{
	mlx_string_put(f->mlx_ptr, f->win_ptr, 7, 550,
			0xaf8970, "'W A S D'   move");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 7, 580,
			0xaf8970, "'SHIFT'      run");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 7, 610,
			0xaf8970, "'T' show texture");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 7, 640,
			0xaf8970, "'ENTER'    reset");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 7, 670,
			0xaf8970, "'ESC'       quit");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 7, 700,
			0xaf8970, "'H'   hide hints");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 7, 730,
			0xaf8970, "'P'    slow mode");
}
