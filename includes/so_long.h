/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 16:44:37 by qfrederi      #+#    #+#                 */
/*   Updated: 2021/12/16 17:04:11 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*Wallimg;
	void	*collect;
	void	*exit;
	char	*map;
	char	*Wall_path;
	char	**mapline;
	void	*background_img;
	char	*relative_path;
	char	*background_path;
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
	int		count_collect;
	int		pickup_collect;
	int		movement;
	int		img_width;
	int		img_height;
}				t_vars;	

void	*mapinput(t_vars *vars);
void	readmap(t_vars *vars);
void	checkmap(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		close_game(t_vars *vars);
int		count_line(t_vars *vars);
int		checkwall(t_vars *vars);
int		check_collect(t_vars *vars);
int		pickup_collect(t_vars *vars);
int		display_move(t_vars *vars);

#endif