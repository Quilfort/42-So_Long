/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 16:44:37 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/02/17 11:27:21 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <get_next_line.h>
# include <libft.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*wallimg;
	void	*collect;
	void	*exit;
	void	*win;
	char	**mapline;
	void	*background_img;
	void	*win_img;
	char	move_screen;
	int		hero_x;
	int		hero_y;
	int		start_x;
	int		start_y;
	int		screen_x;
	int		screen_y;
	int		wall_x;
	int		wall_y;
	int		exit_x;
	int		exit_y;
	int		count;
	int		c;
	int		p;
	int		e;
	int		f_map;
	int		i_map;
	int		count_collect;
	int		pickup_collect;
	int		movement;
	int		img_width;
	int		img_height;
}				t_vars;	

// use_map.c
void	mapinput(t_vars *vars, char *argv[]);

// error_map.c
void	map_error(t_vars *vars);
void	print_error(void);

// check_map.c
void	check_map(t_vars *vars);
int		check_wall(t_vars *vars);
void	check_collect(t_vars *vars);

// write_map.c
void	put_map(t_vars *vars);

// directions.c
void	move_left(int *x, int *y, t_vars *vars);
void	move_down(int *x, int *y, t_vars *vars);
void	move_right(int *x, int *y, t_vars *vars);
void	move_up(int *x, int *y, t_vars *vars);

// display_info.c
void	pickup_collect(t_vars *vars);
void	display_move(t_vars *vars);
void	print_steps(t_vars *vars);

// exit.c
int		close_game(t_vars *vars);
void	win_screen(int *x, int *y, t_vars *vars);
int		key_hook_exit(int keycode, t_vars *vars);

#endif