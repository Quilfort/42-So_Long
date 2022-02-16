/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfrederi <qfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:10:40 by qfrederi          #+#    #+#             */
/*   Updated: 2022/02/16 15:34:19 by qfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	move_left(int *x, int *y, t_vars *vars)
{
	put_map(vars);
	*x = *x - 63;
	vars->hero_x = *x;
	if (check_wall(vars) == 1)
	{
		*x = *x + 63;
		vars->hero_x = *x;
	}
	else
		display_move(vars);
	print_steps(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, *x, *y);
}

void	move_down(int *x, int *y, t_vars *vars)
{
	put_map(vars);
	*y = *y + 63;
	vars->hero_y = *y;
	if (check_wall(vars) == 1)
	{
		*y = *y - 63;
		vars->hero_y = *y;
	}
	else
		display_move(vars);
	print_steps(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, *x, *y);
}

void	move_right(int *x, int *y, t_vars *vars)
{
	put_map(vars);
	*x = *x + 63;
	vars->hero_x = *x;
	if (check_wall(vars) == 1)
	{
		*x = *x - 63;
		vars->hero_x = *x;
	}
	else
		display_move(vars);
	print_steps(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, *x, *y);
}

void	move_up(int *x, int *y, t_vars *vars)
{
	put_map(vars);
	*y = *y - 63;
	vars->hero_y = *y;
	if (check_wall(vars) == 1)
	{
		*y = *y + 63;
		vars->hero_y = *y;
	}
	else
		display_move(vars);
	print_steps(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, *x, *y);
}
