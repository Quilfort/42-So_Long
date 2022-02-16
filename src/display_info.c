/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_info.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 14:44:10 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/02/16 12:42:45 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	display_move(t_vars *vars)
{
	static int	count;

	count = count + 1;
	vars->movement = count;
	write(1, "Steps ", 6);
	ft_putnbr_fd(count, 1);
	write(1, "\n", 2);
}

void	pickup_collect(t_vars *vars)
{
	static int	count;

	count = count + 1;
	vars->pickup_collect = count;
}

void	print_steps(t_vars *vars)
{
	char	*print;

	print = ft_itoa(vars->movement);
	if (!print)
	{
		ft_putendl_fd("Can't Display Steps", 1);
		exit (0);
	}
	mlx_string_put(vars->mlx, vars->mlx_win, vars->screen_x - 63, 63, \
	0xffffff, print);
	free(print);
}
