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
}	t_entity;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	int			img_width;
	int			img_height;
	t_map		*map;
	t_entity 	*player;
}	t_mlx;

t_map		*new_map(void);
t_mlx		*new_mlx(t_map *map);
t_coords	*calculate_window_size(char **map);
t_entity	*new_player(char **map);
t_coords	*find_player(char **map);
char		**fillmap(char	*file);
void		generate_map(char *map, t_mlx *mlx, int y);
void		movement(t_mlx *mlx);
#endif
