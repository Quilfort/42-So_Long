/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 16:44:37 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/02/09 17:25:00 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

void	load_images(t_vars *vars);
void	*mapinput(t_vars *vars, char *argv[]);
int		fd_check(int fd);
void	put_map(t_vars *vars);
int		count_line(t_vars *vars, char *map);
void	write_wall(t_vars *vars, int *x, int *y);
void	write_empty(t_vars *vars, int *x, int *y);
void	write_collect(t_vars *vars, int *x, int *y);
void	write_player(t_vars *vars, int *x, int *y);
void	write_exit(t_vars *vars, int *x, int *y);
void	map_error(t_vars *vars);
void	wall_error(t_vars *vars);
void	item_error(t_vars *vars);
void	unknown_error(t_vars *vars);
void	print_error(t_vars *vars);
void	checkmap(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	move_left(int *x, int *y, t_vars *vars);
void	move_down(int *x, int *y, t_vars *vars);
void	move_right(int *x, int *y, t_vars *vars);
void	move_up(int *x, int *y, t_vars *vars);
int		checkwall(t_vars *vars);
int		find_wall(t_vars *vars);
int		check_collect(t_vars *vars);
void	pickup_collect(t_vars *vars);
void	display_move(t_vars *vars);
void	print_screen(t_vars *vars);
int		close_game(t_vars *vars);
void	winscreen(int *x, int *y, t_vars *vars);
int		key_hook_exit(int keycode, t_vars *vars);

#endif