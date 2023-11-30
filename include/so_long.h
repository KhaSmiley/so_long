/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:59:34 by kboulkri          #+#    #+#             */
/*   Updated: 2023/11/26 19:11:25 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define FALSE -1
# define TRUE 0

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_data
{
	char	**map;

	void	*mlx_ptr;
	void	*win_ptr;

	void	*texture[5];

	int		width;
	int		height;

	int		nb_line;
	int		len_line;
	int		len;

	int		player_pos_y;
	int		player_pos_x;
	int		exit_pos_y;
	int		exit_pos_x;

	int		nb_move;
	int		nb_exit;
	int		nb_coins;
	int		nb_player;
}			t_data;

/* Count_ECP */

int			count_coins(t_data *data);
int			count_exit(t_data *data);
int			count_player(t_data *data);
int			find_player_pos(t_data *data);

/* Exit_and_free.c */

void		mlx_destroy_image_if_exist(void *mlx_ptr, void *img_ptr);
int			exit_and_free(t_data *data);

/* Flood_fill*/

void		flood_fill_map(char **map, t_point size, t_point cur);
int			find_player_position(t_data *data);
int			start_flood_fill(t_data *data);
int			flood_fill(char **map, t_point size, t_point begin);

/* Free */

int			free_tab(char **tab);

/* Graphics.c */

void		init_single_img(void **img_ptr, t_data *data, char *path);
void		texture_init(t_data *data);
void		display_map(t_data *data);
void		ft_display_map_finder(t_data *data, int i, int j);
int			main_graphics(t_data *data);

/* Move_player.c */

void		move_right(t_data *data);
void		move_left(t_data *data);
void		move_up(t_data *data);
void		move_down(t_data *data);
void		update_player_position(t_data *data, int new_x, int new_y, char n);

/* Parsing_utils.c */
int			ext_check(char *argv);
int			check_if_wrong_char_map(t_data *data);
int			check_first_and_last_line(t_data *data);
int			check_border_map(t_data *data);
int			count_exit_and_coins(t_data *data);

/* Parsing_utils_two.c*/

int	check_size(t_data *data);

/* Parsing.c */

char		**check_to_push_map(char *path, t_data *data);
char		**push_map_to_double_array(char *path, int nb_line, t_data *data);
int			check_map_rectangle(char *path, t_data *data);
int			map_complete_check(char **argv, t_data *data);

#endif