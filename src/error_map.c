/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 13:59:48 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/01/24 13:49:06 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "../includes/so_long.h"
#include "../library/libft/libft.h"
#include <stdio.h>
#include <mlx.h>

void	map_error(t_vars *vars)
{
	item_error(vars);
	wall_error(vars);
	unknown_error(vars);
}

void	unknown_error(t_vars *vars)
{
	int	f;
	int	i;

	f = 0;
	i = 0;
	while (f < vars->count)
	{
		while (vars->mapline[f][i] != '\0')
		{
			if (vars->mapline[f][i] != 'C' && vars->mapline[f][i] != 'P' \
			&& vars->mapline[f][i] != 'E' \
			&& vars->mapline[f][i] != '1' && vars->mapline[f][i] != '0')
				print_error(vars);
			i++;
		}
		i = 0;
		f++;
	}
}

void	item_error(t_vars *vars)
{
	int	f;
	int	i;

	f = 0;
	i = 0;
	vars->c = 0;
	vars->p = 0;
	vars->e = 0;
	while (f < vars->count)
	{
		while (vars->mapline[f][i] != '\0')
		{
			if (vars->mapline[f][i] == 'C')
				vars->c = vars->c + 1;
			if (vars->mapline[f][i] == 'P')
				vars->p = vars->p + 1;
			if (vars->mapline[f][i] == 'E')
				vars->e = vars->e + 1;
			i++;
		}
		i = 0;
		f++;
	}
	if (vars->c < 1 || vars->p != 1 || vars->e == 0)
		print_error(vars);
}

void	wall_error(t_vars *vars)
{
	int	f;
	int	i;
	int	max;

	f = 0;
	i = 0;
	max = ft_strlen(vars->mapline[i]);
	while (f < vars->count)
	{
		while (vars->mapline[f][i] != '\0')
		{
			if (vars->mapline[0][i] != '1' || vars->mapline[f][0] != '1' || \
			vars->mapline[f][max - 1] != '1' || \
			vars->mapline[vars->count - 1][i] != '1')
				print_error(vars);
			i++;
		}
		i = 0;
		f++;
	}
}

void	print_error(t_vars *vars)
{
	char	*error;

	error = "ERROR";
	ft_putstr_fd(error, 1);
	exit(0);
}