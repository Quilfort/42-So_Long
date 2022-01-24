/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   use_map.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:07:22 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/01/24 16:20:46 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "../includes/so_long.h"
#include "../library/libft/libft.h"
#include <stdio.h>
#include <mlx.h>

void	*mapinput(t_vars *vars, char *argv[])
{
	int		fd;
	char	*temp;
	char	*map;
	char	*newmap;

	map = ft_calloc(1, 1);
	if (map == NULL)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	while (map)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		newmap = map;
		map = ft_strjoin(newmap, temp);
		free(newmap);
		free(temp);
	}
	vars->count = count_line(vars, map);
	vars->mapline = ft_split(map, '\n');
	free(map);
	close(fd);
}

int	count_line(t_vars *vars, char *map)
{
	int	i;

	vars->count = 1;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			vars->count++;
		}
		i++;
	}
	return (vars->count);
}

void	put_map(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	vars->i_map = 0;
	vars->f_map = 0;
	while (vars->f_map < vars->count)
	{
		while (vars->mapline[vars->f_map][vars->i_map] != '\0')
		{
			write_wall(vars, &x, &y);
			write_empty(vars, &x, &y);
			write_collect(vars, &x, &y);
			write_player(vars, &x, &y);
			write_exit(vars, &x, &y);
			x = x + 63;
			vars->i_map++;
		}
		vars->i_map = 0;
		x = 0;
		y = y + 63;
		vars->f_map++;
	}
}
