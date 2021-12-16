/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_info.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 14:44:10 by qfrederi      #+#    #+#                 */
/*   Updated: 2021/12/16 17:31:32 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../library/libft/libft.h"
#include <stdio.h>
#include <mlx.h>

int	display_move(t_vars *vars)
{
	static int	count;
	char		temp;

	count = count + 1;
	vars->movement = count;
	printf("Steps %d", vars->movement);
	vars->move_screen = *ft_itoa(vars->movement);
	printf("Itoa Steps %d", vars->move_screen);
}

int	pickup_collect(t_vars *vars)
{
	static int	count;

	count = count + 1;
	vars->pickup_collect = count;
	printf("de is de pickupcount %d", vars->pickup_collect);
}
