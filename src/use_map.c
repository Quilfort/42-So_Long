/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfrederi <qfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:07:22 by qfrederi          #+#    #+#             */
/*   Updated: 2022/02/16 15:19:04 by qfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	count_line(char *map)
{
	int	i;
	int	count;

	count = 1;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			count++;
		}
		i++;
	}
	return (count);
}

static void	split_map(t_vars *vars, char *map)
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
	vars->count = count_line(map);
	vars->mapline = ft_split(map, '\n');
	if (!vars->mapline)
		print_error();
	free(map);
}

static int	fd_check(int fd)
{
	if (fd == -1)
		return (0);
	return (1);
}

void	mapinput(t_vars *vars, char *argv[])
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
}
