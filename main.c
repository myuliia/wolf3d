/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:34:08 by myuliia           #+#    #+#             */
/*   Updated: 2019/02/07 15:34:09 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	init_window(t_wolf *f, char *argv)
{
	char	*str;
	int		h;
	int		w;

	str = ft_strjoin("WOLF3D - ", argv);
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, str);
	system("afplay ./pics/sound1.mp3&");
	f->img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img_ptr,
		&f->bits, &f->line_size, &f->endian);
	f->img_ptr2 = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->addr2 = mlx_get_data_addr(f->img_ptr2,
		&f->bits2, &f->line_size2, &f->endian2);
	ft_strdel(&str);
}

t_alg	*init_alg(void)
{
	t_alg	*alg;

	alg = (t_alg *)malloc(sizeof(t_alg));
	return (alg);
}

void	set_position(t_wolf *f, int x, int y)
{
	if (f->red->map[f->red->width / 2][f->red->height / 2] == 0)
	{
		f->red->x_pos = (f->red->width / 2) + 0.5;
		f->red->y_pos = (f->red->height / 2) + 0.5;
		return ;
	}
	else
	{
		x = -1;
		while (++x < f->red->height)
		{
			y = -1;
			while (++y < f->red->width)
			{
				if (f->red->map[x][y] == 0)
				{
					f->red->x_pos = y + 0.5;
					f->red->y_pos = x + 0.8;
					return ;
				}
			}
		}
	}
	ft_error(7);
}

void	transparent_image(t_wolf *f)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (*(int *)(f->addr2 + 4 * WIDTH * j + i * 4) == 0)
				*(int *)(f->addr2 + 4 * WIDTH * j + i * 4) = TRANS;
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_wolf	*f;

	if (!(f = (t_wolf *)malloc(sizeof(t_wolf))))
		ft_error(9);
	if (argc != 2)
		ft_error(1);
	f->red = ft_read(argv[1]);
	valid_borders(f);
	init_window(f, argv[1]);
	init_text(f);
	transparent_image(f);
	f->alg = init_alg();
	draw_all(f);
	mlx_hook(f->win_ptr, 17, 0, destroy, NULL);
	mlx_hook(f->win_ptr, 3, (1L << 1), ft_key_release, f);
	mlx_hook(f->win_ptr, 2, (1L << 0), ft_key_hook, f);
	mlx_loop_hook(f->mlx_ptr, moving, f);
	mlx_loop(f->mlx_ptr);
	return (0);
}
