/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:14:40 by myuliia           #+#    #+#             */
/*   Updated: 2019/02/08 19:14:41 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void		ft_error(int n)
{
	if (n == 1)
		ft_putstr("\x1b[33musage: ./wolf3d maps\x1b[0m\n");
	if (n == 2)
		ft_putstr("File doesn't open\n");
	if (n == 3)
		ft_putstr("Map isn't valid\n");
	if (n == 4)
		ft_putstr("Map is too small\n");
	if (n == 5)
		ft_putstr("Troubles with borders\n");
	if (n == 6)
		ft_putstr("Map is too big\n");
	if (n == 7)
		ft_putstr("Too many walls\n");
	if (n == 9)
		ft_putstr("Malloc error\n");
	exit(1);
}

int			destroy(void)
{
	system("killall afplay");
	exit(0);
}
