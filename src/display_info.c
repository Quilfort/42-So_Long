/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_info.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 14:44:10 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/01/24 11:19:06 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../library/libft/libft.h"
#include <stdio.h>
#include <mlx.h>

void	display_move(t_vars *vars)
{
	static int	count;
	char		temp;

	count = count + 1;
	vars->movement = count;
}

void	pickup_collect(t_vars *vars)
{
	static int	count;

	count = count + 1;
	vars->pickup_collect = count;
}
