/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   use_map.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:07:22 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/02/14 15:58:48 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <mlx.h>

void	*mapinput(t_vars *vars, char *argv[])
{
	int		fd;
	char	*temp;
	char	*map;
	char	*newmap;

	map = ft_calloc(1, 1);
	if (map == NULL)
		print_error();
	fd = open(argv[1], O_RDONLY);
	if (!fd_check(fd))
		print_error();
	while (map)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		newmap = map;
		map = ft_strjoin(newmap, temp);
		free(newmap);
		free(temp);
	}
	split_map(vars, map);
	close(fd);
	return (0);
}

int	fd_check(int fd)
{
	if (fd == -1)
		return (0);
	return (1);
}

void	split_map(t_vars *vars, char *map)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(map);
	while (map[i] != '\0')
	{
		if (map[length - 1] == '\n')
			print_error();
		if (map[0] == '\n')
			print_error();
		if (map[i] == '\n')
		{
			if (map[i + 1] == '\n')
				print_error();
		}
		i++;
	}
	vars->count = count_line(vars, map);
	vars->mapline = ft_split(map, '\n');
	if (!vars->mapline)
		print_error();
	free(map);
}

int	count_line(t_vars *vars, char *map)
{
	int	i;

	vars->count = 1;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			vars->count++;
		}
		i++;
	}
	return (vars->count);
}

void	put_map(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	vars->i_map = 0;
	vars->f_map = 0;
	while (vars->f_map < vars->count)
	{
		while (vars->mapline[vars->f_map][vars->i_map] != '\0')
		{
			write_wall(vars, &x, &y);
			write_empty(vars, &x, &y);
			write_collect(vars, &x, &y);
			write_player(vars, &x, &y);
			write_exit(vars, &x, &y);
			x = x + 63;
			vars->i_map++;
		}
		vars->i_map = 0;
		x = 0;
		y = y + 63;
		vars->f_map++;
	}
}
