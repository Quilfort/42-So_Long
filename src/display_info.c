/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_info.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 14:44:10 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/01/17 11:46:54 by qfrederi      ########   odam.nl         */
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
}

int	pickup_collect(t_vars *vars)
{
	static int	count;

	count = count + 1;
	vars->pickup_collect = count;
	printf("de is de pickupcount %d", vars->pickup_collect);
}
