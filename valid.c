/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:04:53 by myuliia           #+#    #+#             */
/*   Updated: 2019/02/21 13:04:53 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	ft_valid_symbol(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] >= '0' && s[i] <= '9')
			|| s[i] == ' ' || s[i] == '\n')
			i++;
		else
			ft_error(3);
	}
}

void	valid_borders(t_wolf *f)
{
	int i;
	int j;

	i = -1;
	while (++i < f->red->height)
	{
		j = -1;
		while (++j < f->red->width)
		{
			if (j == 0 || j == (f->red->width - 1))
				if (f->red->map[i][j] == 0)
					ft_error(5);
		}
		if (i == 0 || i == (f->red->height - 1))
		{
			j = 0;
			while (j < f->red->width)
			{
				if (f->red->map[i][j] == 0)
					ft_error(5);
				else
					j++;
			}
		}
	}
}
