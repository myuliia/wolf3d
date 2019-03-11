/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 21:00:22 by myuliia           #+#    #+#             */
/*   Updated: 2019/02/08 21:00:23 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

char	*read_two(t_read *red, char *buf, char *tmp, char *line)
{
	ft_valid_symbol(line);
	if (red->width == ft_count_words(line, ' ') || red->height == 1)
		red->width = ft_count_words(line, ' ');
	else
		ft_error(3);
	if (red->width < 3)
		ft_error(4);
	tmp = ft_strjoin(buf, line);
	free(buf);
	free(line);
	buf = ft_strjoin(tmp, "\n");
	free(tmp);
	return (buf);
}

t_read	*ft_read(char *file)
{
	char	*line;
	char	*buf;
	char	**map;
	char	*tmp;
	t_read	*red;

	red = (t_read *)malloc(sizeof(t_read));
	red->height = 0;
	red->width = 0;
	buf = ft_strdup("\0");
	if ((red->fd = open(file, O_RDONLY)) < 0)
		ft_error(2);
	while ((get_next_line(red->fd, &line)) == 1 && ++red->height)
	{
		buf = read_two(red, buf, tmp, line);
	}
	if (!red->width)
		ft_error(3);
	close(red->fd);
	map = ft_strsplit(buf, '\n');
	free(buf);
	map_in_int(map, red);
	close(red->fd);
	return (red);
}

void	map_in_int(char **map, t_read *red)
{
	char	**tmp;
	int		y;
	int		x;

	y = -1;
	red->map = (int**)malloc(sizeof(int*) * red->height);
	if (red->height < 3)
		ft_error(4);
	if (red->height > 97 || red->width > 97)
		ft_error(6);
	while (++y < red->height)
	{
		red->map[y] = (int*)malloc(sizeof(int) * red->width);
		tmp = ft_strsplit(map[y], ' ');
		free(map[y]);
		x = -1;
		while (++x < red->width)
		{
			red->map[y][x] = atoi(tmp[x]);
			free(tmp[x]);
		}
		free(tmp);
	}
	free(map);
}
