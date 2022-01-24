/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   directions.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 13:10:40 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/01/24 11:17:01 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <so_long.h>
#include "get_next_line/get_next_line.h"
#include "../library/libft/libft.h"

void	move_left(int *x, int *y, t_vars *vars)
{
	put_map(vars);
	*x = *x - 63;
	vars->hero_x = *x;
	if (checkwall(vars) == 1)
	{
		*x = *x + 63;
		vars->hero_x = *x;
		mlx_string_put(vars->mlx, vars->mlx_win, vars->screen_x - 63, 63, \
		0xffffff, ft_itoa(vars->movement));
	}
	else
	{
		display_move(vars);
		mlx_string_put(vars->mlx, vars->mlx_win, vars->screen_x - 63, 63, \
		0xffffff, ft_itoa(vars->movement));
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, *x, *y);
}

void	move_down(int *x, int *y, t_vars *vars)
{
	put_map(vars);
	*y = *y + 63;
	vars->hero_y = *y;
	if (checkwall(vars) == 1)
	{
		*y = *y - 63;
		vars->hero_y = *y;
		mlx_string_put(vars->mlx, vars->mlx_win, vars->screen_x - 63, 63, \
		0xffffff, ft_itoa(vars->movement));
	}
	else
	{
		display_move(vars);
		mlx_string_put(vars->mlx, vars->mlx_win, vars->screen_x - 63, 63, \
		0xffffff, ft_itoa(vars->movement));
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, *x, *y);
}

void	move_right(int *x, int *y, t_vars *vars)
{
	put_map(vars);
	*x = *x + 63;
	vars->hero_x = *x;
	if (checkwall(vars) == 1)
	{
		*x = *x - 63;
		vars->hero_x = *x;
		mlx_string_put(vars->mlx, vars->mlx_win, vars->screen_x - 63, 63, \
		0xffffff, ft_itoa(vars->movement));
	}
	else
	{
		display_move(vars);
		mlx_string_put(vars->mlx, vars->mlx_win, vars->screen_x - 63, 63, \
		0xffffff, ft_itoa(vars->movement));
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, *x, *y);
}

void	move_up(int *x, int *y, t_vars *vars)
{
	put_map(vars);
	*y = *y - 63;
	vars->hero_y = *y;
	if (checkwall(vars) == 1)
	{
		*y = *y + 63;
		vars->hero_y = *y;
		mlx_string_put(vars->mlx, vars->mlx_win, vars->screen_x - 63, 63, \
		0xffffff, ft_itoa(vars->movement));
	}
	else
	{
		display_move(vars);
		mlx_string_put(vars->mlx, vars->mlx_win, vars->screen_x - 63, 63, \
		0xffffff, ft_itoa(vars->movement));
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, *x, *y);
}
