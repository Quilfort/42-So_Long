/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 16:17:13 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/01/20 16:49:20 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <so_long.h>
#include "get_next_line/get_next_line.h"
#include "../library/libft/libft.h"

void	winscreen(int *x, int *y, t_vars *vars)
{
	if (*x == vars->exit_x && *y == vars->exit_y && vars->count_collect == 0)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		vars->win = "./background.xpm";
		vars->mlx_win = mlx_new_window(vars->mlx, vars->screen_x, \
		vars->screen_y, "You Won");
		vars->win_img = mlx_xpm_file_to_image(vars->mlx, vars->win, \
		&vars->img_width, &vars->img_height);
		mlx_hook(vars->mlx_win, 17, 0, close_game, &vars);
		mlx_key_hook(vars->mlx_win, key_hook_exit, vars);
	}	
}

int	close_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(0);
}

int	key_hook_exit(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
}
