/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 16:31:45 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/01/24 16:18:22 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <so_long.h>
#include "get_next_line/get_next_line.h"
#include "../library/libft/libft.h"

int	key_hook(int keycode, t_vars *vars)
{
	static int	x;
	static int	y;

	if (x == 0 && y == 0)
	{
		x = vars->start_x;
		y = vars->start_y;
		vars->hero_x = vars->start_x;
		vars->hero_y = vars->start_y;
	}
	mlx_string_put(vars->mlx, vars->mlx_win, 0, 63, 0xffffff, \
	ft_itoa(vars->movement));
	if (keycode == 0)
		move_left(&x, &y, vars);
	if (keycode == 1)
		move_down(&x, &y, vars);
	if (keycode == 2)
		move_right(&x, &y, vars);
	if (keycode == 13)
		move_up(&x, &y, vars);
	winscreen(&x, &y, vars);
	key_hook_exit(keycode, vars);
	return (0);
}

void	load_images(t_vars *vars)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->relative_path, \
	&vars->img_width, &vars->img_height);
	vars->background_img = mlx_xpm_file_to_image(vars->mlx, \
	vars->grass_path, &vars->img_width, &vars->img_height);
	vars->wallimg = mlx_xpm_file_to_image(vars->mlx, vars->wall_path, \
	&vars->img_width, &vars->img_height);
	vars->collect = mlx_xpm_file_to_image(vars->mlx, vars->collect, \
	&vars->img_width, &vars->img_height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, vars->exit, \
	&vars->img_width, &vars->img_height);
	vars->win_img = mlx_xpm_file_to_image(vars->mlx, vars->winscreen_path, \
	&vars->img_width, &vars->img_height);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
	{
		return (0);
	}
	vars.grass_path = "./Grass.xpm";
	vars.relative_path = "./Character.xpm";
	vars.wall_path = "./Wall.xpm";
	vars.collect = "./collect.xpm";
	vars.exit = "./exit.xpm";
	vars.winscreen_path = "./background.xpm";
	vars.mlx = mlx_init();
	mapinput(&vars, argv);
	map_error(&vars);
	checkmap(&vars);
	vars.mlx_win = mlx_new_window(vars.mlx, vars.screen_x, \
	vars.screen_y, "Courtyard Ball");
	load_images(&vars);
	put_map(&vars);
	check_collect(&vars);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_hook(vars.mlx_win, 17, 0, close_game, &vars);
	mlx_loop(vars.mlx);
}
