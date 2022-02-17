/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 13:59:48 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/02/17 11:36:56 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	unknown_error(t_vars *vars)
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
				print_error();
			i++;
		}
		i = 0;
		f++;
	}
}

static void	item_error(t_vars *vars)
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
		print_error();
}

static void	wall_error(t_vars *vars)
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
				print_error();
			i++;
		}
		i = 0;
		f++;
	}
}

void	print_error(void)
{
	char	*error;

	error = "Code 42: Map Error";
	ft_putstr_fd(error, 1);
	exit(0);
}

void	map_error(t_vars *vars)
{
	if (vars->mapline[0] == NULL)
		print_error();
	item_error(vars);
	wall_error(vars);
	unknown_error(vars);
}
