/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 16:17:13 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/02/16 15:19:00 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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
	return (0);
}

void	win_screen(int *x, int *y, t_vars *vars)
{
	if (*x == vars->exit_x && *y == vars->exit_y && vars->count_collect == 0)
	{
		write(1, "You escaped the castle!\n", 25);
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		vars->mlx_win = mlx_new_window(vars->mlx, 192, \
		192, "Hooray");
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->win_img, 0, 0);
		mlx_key_hook(vars->mlx_win, key_hook_exit, vars);
		mlx_hook(vars->mlx_win, 17, 0, close_game, vars);
	}	
}
