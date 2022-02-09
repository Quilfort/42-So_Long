/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 16:31:45 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/02/09 15:22:16 by qfrederi      ########   odam.nl         */
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
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./Character.xpm", \
	&vars->img_width, &vars->img_height);
	vars->background_img = mlx_xpm_file_to_image(vars->mlx, \
	"./Grass.xpm", &vars->img_width, &vars->img_height);
	vars->wallimg = mlx_xpm_file_to_image(vars->mlx, "./Wall.xpm", \
	&vars->img_width, &vars->img_height);
	vars->collect = mlx_xpm_file_to_image(vars->mlx, "./collect.xpm", \
	&vars->img_width, &vars->img_height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "./exit.xpm", \
	&vars->img_width, &vars->img_height);
	vars->win_img = mlx_xpm_file_to_image(vars->mlx, "./background.xpm", \
	&vars->img_width, &vars->img_height);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	size_t	arglen;

	arglen = ft_strlen(argv[1]);
	if (argc != 2)
		return (0);
	if (argv[1][arglen - 1] != 'r' && argv[1][arglen - 2] != 'e' && \
		argv[1][arglen - 3] != 'b')
	{
		ft_putendl_fd("Game can only run .ber files", 1);
		return (0);
	}
	vars.mlx = mlx_init();
	mapinput(&vars, argv);
	map_error(&vars);
	checkmap(&vars);
	vars.mlx_win = mlx_new_window(vars.mlx, vars.screen_x, \
	vars.screen_y, "Courtyard Ball");
	load_images(&vars);
	put_map(&vars);
	check_collect(&vars);
	mlx_hook(vars.mlx_win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.mlx_win, 17, 0, close_game, &vars);
	mlx_loop(vars.mlx);
}
