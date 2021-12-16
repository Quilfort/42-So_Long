/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   use_map.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:07:22 by qfrederi      #+#    #+#                 */
/*   Updated: 2021/12/16 12:52:51 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "../includes/so_long.h"
#include "../library/libft/libft.h"
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

void	readmap(t_vars *vars)
{
	int	f;
	int	i;
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	i = 0;
	f = 0;
	count = count_line(vars);
	while (f < count)
	{
		while (vars->mapline[f][i] != '\0')
		{
			if (vars->mapline[f][i] == '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
				vars->Wallimg, x, y);
			}
			if (vars->mapline[f][i] == '0')
			{
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
				vars->background_img, x, y);
			}
			if (vars->mapline[f][i] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
				vars->collect, x, y);
				if (vars->hero_x == x && vars->hero_y == y)
				{
					vars->mapline[f][i] = '0';
					mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
					vars->background_img, x, y);
					pickup_collect(vars);
					check_collect(vars);
				}
			}
			if (vars->mapline[f][i] == 'P')
			{
				vars->start_x = x;
				vars->start_y = y;
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
				vars->img, x, y);
				vars->mapline[f][i] = '0';
			}
			if (vars->mapline[f][i] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
				vars->exit, x, y);
				vars->exit_x = x;
				vars->exit_y = y;
			}
			x = x + 64;
			i++;
		}
		i = 0;
		x = 0;
		y = y + 64;
		f++;
	}
}
