/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 15:26:29 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/01/20 15:45:38 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "../includes/so_long.h"
#include "../library/libft/libft.h"
#include <stdio.h>
#include <mlx.h>

void	write_wall(t_vars *vars, int *x, int *y)
{
	if (vars->mapline[vars->f_map][vars->i_map] == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->wallimg, *x, *y);
	}
}

void	write_empty(t_vars *vars, int *x, int *y)
{
	if (vars->mapline[vars->f_map][vars->i_map] == '0')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->background_img, *x, *y);
	}
}

void	write_collect(t_vars *vars, int *x, int *y)
{
	if (vars->mapline[vars->f_map][vars->i_map] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->collect, *x, *y);
		if (vars->hero_x == *x && vars->hero_y == *y)
		{
			vars->mapline[vars->f_map][vars->i_map] = '0';
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
			vars->background_img, *x, *y);
			pickup_collect(vars);
			check_collect(vars);
		}
	}
}

void	write_player(t_vars *vars, int *x, int *y)
{
	if (vars->mapline[vars->f_map][vars->i_map] == 'P')
	{
		vars->start_x = *x;
		vars->start_y = *y;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->img, *x, *y);
		vars->mapline[vars->f_map][vars->i_map] = '0';
	}
}

void	write_exit(t_vars *vars, int *x, int *y)
{
	if (vars->mapline[vars->f_map][vars->i_map] == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->exit, *x, *y);
		vars->exit_x = *x;
		vars->exit_y = *y;
	}
}