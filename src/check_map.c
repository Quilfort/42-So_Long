/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 12:20:08 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/02/14 12:22:33 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <mlx.h>

void	checkmap(t_vars *vars)
{
	int	f;
	int	i;

	f = 0;
	i = 0;
	while (f < vars->count)
	{
		while (vars->mapline[f][i] != '\0')
		{
			i++;
		}
		vars->screen_x = i * 63;
		i = 0;
		f++;
	}
	vars->screen_y = f * 63;
}

int	checkwall(t_vars *vars)
{
	int	f;
	int	i;

	vars->wall_x = 0;
	vars->wall_y = 0;
	i = 0;
	f = 0;
	while (f < vars->count)
	{
		while (vars->mapline[f][i] != '\0')
		{
			if (vars->mapline[f][i] == '1')
			{
				if (find_wall(vars) == 1)
					return (1);
			}	
			vars->wall_x = vars->wall_x + 63;
			i++;
		}
		i = 0;
		vars->wall_x = 0;
		vars->wall_y = vars->wall_y + 63;
		f++;
	}
	return (0);
}

int	find_wall(t_vars *vars)
{
	if (vars->wall_x == vars->hero_x && vars->wall_y == vars->hero_y)
		return (1);
	else
		return (0);
}

int	check_collect(t_vars *vars)
{
	int	f;
	int	i;

	i = 0;
	f = 0;
	vars->count_collect = 0;
	while (f < vars->count)
	{
		while (vars->mapline[f][i] != '\0')
		{
			if (vars->mapline[f][i] == 'C')
			{
				vars->count_collect = vars->count_collect + 1;
			}	
			i++;
		}
		i = 0;
		f++;
	}
	return (0);
}
