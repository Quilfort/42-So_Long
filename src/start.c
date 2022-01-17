/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 16:31:45 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/01/17 13:49:05 by qfrederi      ########   odam.nl         */
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
	mlx_string_put(vars->mlx, vars->mlx_win, 0, 64, 0xffffff, ft_itoa(vars->movement));
	printf("Keypress: %d\n", keycode);
	if (keycode == 0)
	{
		move_left(&x, &y, vars);
	}
	if (keycode == 1)
	{
		move_down(&x, &y, vars);
	}
	if (keycode == 2)
	{
		move_right(&x, &y, vars);
	}
	if (keycode == 13)
	{
		move_up(&x, &y, vars);
	}
	if (x == vars->exit_x && y == vars->exit_y && vars->count_collect == 0)
	{
		// vars->mlx_win = mlx_new_window(vars->mlx, vars->screen_x, \
		// vars->screen_y, "You Won");
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}	
}

int	close_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(0);
}

int	main(void)
{
	t_vars	vars;

	vars.background_path = "./Grass.xpm";
	vars.relative_path = "./Character.xpm";
	vars.Wall_path = "./Wall.xpm";
	vars.collect = "./collect.xpm";
	vars.exit = "./exit.xpm";
	vars.mlx = mlx_init();
	mapinput(&vars);
	checkmap(&vars);
	vars.mlx_win = mlx_new_window(vars.mlx, vars.screen_x, \
	vars.screen_y, "Walking on Grass");
	vars.img = mlx_xpm_file_to_image(vars.mlx, vars.relative_path, \
	&vars.img_width, &vars.img_height);
	vars.background_img = mlx_xpm_file_to_image(vars.mlx, vars.background_path, \
	&vars.img_width, &vars.img_height);
	vars.Wallimg = mlx_xpm_file_to_image(vars.mlx, vars.Wall_path, \
	&vars.img_width, &vars.img_height);
	vars.collect = mlx_xpm_file_to_image(vars.mlx, vars.collect, \
	&vars.img_width, &vars.img_height);
	vars.exit = mlx_xpm_file_to_image(vars.mlx, vars.exit, \
	&vars.img_width, &vars.img_height);
	readmap(&vars);
	check_collect(&vars);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_hook(vars.mlx_win, 17, 0, close_game, &vars);
	mlx_loop(vars.mlx);
}
