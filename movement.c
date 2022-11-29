/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:44:38 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/11/15 16:44:39 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

/// Permet de se deplacer vers la droite en appuyant sur D
/// \param mlx structure de la window

void	movement_right(t_mlx *mlx)
{
	t_coords	*loc;
	t_map		*map;

	loc = mlx->player->coords;
	map = mlx->map;
	if (map->map[loc->y][loc->x + 1] == 'B')
		close_window(mlx);
	if (mlx->player->coins == mlx->coins
		&& map->map[loc->y][loc->x + 1] == 'E')
	{
		ft_printf("Gagnez !!!!\n\n");
		close_window(mlx);
	}
	else if (map->map[loc->y][loc->x + 1] != '1' &&
	map->map[loc->y][loc->x + 1] != 'E')
	{
		drow_movement(loc->x, loc->y, mlx, "Terrain.xpm");
		check_movement(mlx, loc->x + 1, loc->y);
		move_tostr(mlx);
	}
}
/// Permet de se deplacer sur la gauche en appuyant sur a
/// \param mlx structure de la window

void	movement_left(t_mlx *mlx)
{
	t_coords	*loc;
	t_map		*map;

	loc = mlx->player->coords;
	map = mlx->map;
	if (mlx->player->coins == mlx->coins
		&& map->map[loc->y][loc->x - 1] == 'E')
	{
		ft_printf("Gagnez !!!!\n\n");
		close_window(mlx);
	}
	else if (map->map[loc->y][loc->x - 1] != '1'
		&& map->map[loc->y][loc->x - 1] != 'E')
	{
		drow_movement(loc->x, loc->y, mlx, "Terrain.xpm");
		check_movement(mlx, loc->x - 1, loc->y);
		move_tostr(mlx);
	}
}
/// Permet de se deplacer vers le haut en appuyant sur W
/// \param mlx structure de la window

void	movement_up(t_mlx *mlx)
{
	t_coords	*loc;
	t_map		*map;

	loc = mlx->player->coords;
	map = mlx->map;
	if (mlx->player->coins == mlx->coins
		&& map->map[loc->y - 1][loc->x] == 'E')
	{
		ft_printf("Gagnez !!!!\n\n");
		close_window(mlx);
	}
	else if (map->map[loc->y - 1][loc->x] != '1'
		&& map->map[loc->y - 1][loc->x] != 'E')
	{
		drow_movement(loc->x, loc->y, mlx, "Terrain.xpm");
		check_movement(mlx, loc->x, loc->y - 1);
		move_tostr(mlx);
	}
}
/// Permet de se deplacer vers le bas en appuyant sur S
/// \param mlx structure de la window

void	movement_down(t_mlx *mlx)
{
	t_coords	*loc;
	t_map		*map;

	loc = mlx->player->coords;
	map = mlx->map;
	if (map->map[loc->y + 1][loc->x] == 'B')
		close_window(mlx);
	else if (mlx->player->coins == mlx->coins
		&& map->map[loc->y + 1][loc->x] == 'E')
	{
		ft_printf("Gagnez !!!!\n\n");
		close_window(mlx);
	}
	else if (map->map[loc->y + 1][loc->x] != '1'
		&& map->map[loc->y + 1][loc->x] != 'E')
	{
		drow_movement(loc->x, loc->y, mlx, "Terrain.xpm");
		check_movement(mlx, loc->x, loc->y + 1);
		move_tostr(mlx);
	}
}

void	check_movement(t_mlx *mlx, int x, int y)
{
	t_map		*map;
	t_coords	*loc;

	loc = malloc(sizeof(*loc));
	loc->x = x;
	loc->y = y;
	map = mlx->map;
	drow_movement(loc->x, loc->y, mlx, "Player.xpm");
	if (map->map[loc->y][loc->x] == 'C')
	{
		map->map[loc->y][loc->x] = '0';
		mlx->player->coins++;
	}
	mlx->player->coords->y = y;
	mlx->player->coords->x = x;
	mlx->move++;
	free(loc);
}
