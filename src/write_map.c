/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 15:26:29 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/02/17 11:11:38 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	write_wall_empty(t_vars *vars, int *x, int *y)
{
	if (vars->mapline[vars->f_map][vars->i_map] == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->wallimg, *x, *y);
	}
	if (vars->mapline[vars->f_map][vars->i_map] == '0')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->background_img, *x, *y);
	}
}

static void	write_collect(t_vars *vars, int *x, int *y)
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

static void	write_player(t_vars *vars, int *x, int *y)
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

static void	write_exit(t_vars *vars, int *x, int *y)
{
	if (vars->mapline[vars->f_map][vars->i_map] == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->exit, *x, *y);
		vars->exit_x = *x;
		vars->exit_y = *y;
	}
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
			write_wall_empty(vars, &x, &y);
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
