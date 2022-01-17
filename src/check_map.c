/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 12:20:08 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/01/17 14:04:50 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../library/libft/libft.h"
#include <stdio.h>
#include <mlx.h>

void	checkmap(t_vars *vars)
{
	int	f;
	int	i;
	int	count;

	f = 0;
	i = 0;
	count = count_line(vars);
	while (f < count)
	{
		while (vars->mapline[f][i] != '\0')
		{
			i++;
		}
		vars->screen_x = i * 64;
		i = 0;
		f++;
	}
	vars->screen_y = f * 64;
}

int	checkwall(t_vars *vars)
{
	int	f;
	int	i;
	int	count;

	vars->wall_x = 0;
	vars->wall_y = 0;
	i = 0;
	f = 0;
	count = count_line(vars);
	while (f < count)
	{
		while (vars->mapline[f][i] != '\0')
		{
			if (vars->mapline[f][i] == '1')
			{
				if (vars->wall_x == vars->hero_x && \
				vars->wall_y == vars->hero_y)
				{
					return (1);
				}
			}	
			vars->wall_x = vars->wall_x + 64;
			i++;
		}
		i = 0;
		vars->wall_x = 0;
		vars->wall_y = vars->wall_y + 64;
		f++;
	}
}

int	check_collect(t_vars *vars)
{
	int	f;
	int	i;
	int	count;

	i = 0;
	f = 0;
	vars->count_collect = 0;
	count = count_line(vars);
	while (f < count)
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
	printf("de is de count %d", vars->count_collect);
}
