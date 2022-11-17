/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:58:29 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/10/31 21:58:30 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_map
{
	t_coords	*coords_max;
	char		**map;
}	t_map;

typedef struct s_entity
{
	t_coords	*coords;
	void		*img;
	int			coins;
}	t_entity;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	int			img_width;
	int			img_height;
	int			move;
	int			coins;
	t_map		*map;
	t_entity	*player;
	t_coords 	*cp;
}	t_mlx;

//Window.c
t_mlx		*new_mlx(t_map *map);
t_coords	*calculate_window_size(char **map);
void		generate_map(char *map, t_mlx *mlx, int y);
void		close_window(t_mlx *mlx);
//Player.c
t_entity	*new_player(char **map);
t_coords	*find_player(char **map);
int			count_coins(char **map);
//Map.c
t_map		*new_map(void);
char		**fillmap(char	*file);
//Movement.c
void		movement_right(t_mlx *mlx);
void		movement_left(t_mlx *mlx);
void		movement_up(t_mlx *mlx);
void		movement_down(t_mlx *mlx);
//Path_finding.c
void		check_coins(t_mlx *mlx);
void		recursive_path(t_mlx *mlx);
int			check_adjacent(t_mlx *mlx);
#endif
