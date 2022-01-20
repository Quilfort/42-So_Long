/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   use_map.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:07:22 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/01/20 15:45:21 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "../includes/so_long.h"
#include "../library/libft/libft.h"
#include <stdio.h>
#include <mlx.h>

void	*mapinput(t_vars *vars)
{
	int		fd;
	char	*temp;

	vars->map = malloc(sizeof(char) * 1);
	vars->map = "\0";
	fd = open("./maps/map1.ber", O_RDONLY);
	temp = get_next_line(fd);
	while (temp != 0)
	{
		vars->map = ft_strjoin(vars->map, temp);
		temp = get_next_line(fd);
	}
	vars->mapline = ft_split(vars->map, '\n');
	close(fd);
}

int	count_line(t_vars *vars)
{
	int	i;
	int	count;

	count = 1;
	i = 0;
	while (vars->map[i] != '\0')
	{
		if (vars->map[i] == '\n')
		{
			count++;
		}
		i++;
	}
	return (count);
}

void	put_map(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	vars->i_map = 0;
	vars->f_map = 0;
	while (vars->f_map < count_line(vars))
	{
		while (vars->mapline[vars->f_map][vars->i_map] != '\0')
		{
			write_wall(vars, &x, &y);
			write_empty(vars, &x, &y);
			write_collect(vars, &x, &y);
			write_player(vars, &x, &y);
			write_exit(vars, &x, &y);
			x = x + 64;
			vars->i_map++;
		}
		vars->i_map = 0;
		x = 0;
		y = y + 64;
		vars->f_map++;
	}
}
