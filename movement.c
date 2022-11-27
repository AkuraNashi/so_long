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
	if (mlx->player->coins == mlx->coins
		&& map->map[loc->y][loc->x + 1] == 'E')
	{
		system("clear");
		ft_printf("Gagnez !!!!\n\n");
		close_window(mlx);
	}
	else if (map->map[loc->y][loc->x + 1] != '1' &&
	map->map[loc->y][loc->x + 1] != 'E')
	{
		drow_movement(loc->x, loc->y, mlx, "Terrain.xpm");
		drow_movement(loc->x + 1, loc->y, mlx, "Player.xpm");
		if (map->map[loc->y][loc->x + 1] == 'C')
		{
			map->map[loc->y][loc->x + 1] = '0';
			mlx->player->coins++;
		}
		mlx->player->coords->x += 1;
		mlx->move++;
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
		&& map->map[loc->y][loc->x + 1] == 'E')
	{
		system("clear");
		ft_printf("Gagnez !!!!\n\n");
		close_window(mlx);
	}
	else if (map->map[loc->y][loc->x - 1] != '1'
		&& map->map[loc->y][loc->x - 1] != 'E')
	{
		drow_movement(loc->x, loc->y, mlx, "Terrain.xpm");
		drow_movement(loc->x - 1, loc->y, mlx, "Player.xpm");
		if (map->map[loc->y][loc->x - 1] == 'C')
		{
			map->map[loc->y][loc->x - 1] = '0';
			mlx->player->coins++;
		}
		mlx->player->coords->x -= 1;
		mlx->move++;
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
		&& map->map[loc->y][loc->x + 1] == 'E')
	{
		system("clear");
		ft_printf("Gagnez !!!!\n\n");
		close_window(mlx);
	}
	else if (map->map[loc->y - 1][loc->x] != '1'
		&& map->map[loc->y - 1][loc->x] != 'E')
	{
		drow_movement(loc->x, loc->y, mlx, "Terrain.xpm");
		drow_movement(loc->x, loc->y - 1, mlx, "Player.xpm");
		if (map->map[loc->y - 1][loc->x] == 'C')
		{
			map->map[loc->y - 1][loc->x] = '0';
			mlx->player->coins++;
		}
		mlx->player->coords->y -= 1;
		mlx->move++;
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
	if (mlx->player->coins == mlx->coins
		&& map->map[loc->y][loc->x + 1] == 'E')
	{
		system("clear");
		ft_printf("Gagnez !!!!\n\n");
		close_window(mlx);
	}
	else if (map->map[loc->y + 1][loc->x] != '1'
		&& map->map[loc->y + 1][loc->x] != 'E')
	{
		drow_movement(loc->x, loc->y, mlx, "Terrain.xpm");
		drow_movement(loc->x, loc->y + 1, mlx, "Player.xpm");
		if (map->map[loc->y + 1][loc->x] == 'C')
		{
			map->map[loc->y + 1][loc->x] = '0';
			mlx->player->coins++;
		}
		mlx->player->coords->y += 1;
		mlx->move++;
	}
}

/// Permet d'effectuer des actions via les entrees claviers
/// \param keycode la touche du claviers
/// \param mlx structure de la window
/// \return
int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		close_window(mlx);
	if (keycode == 2)
		movement_right(mlx);
	else if (keycode == 0)
		movement_left(mlx);
	else if (keycode == 13)
		movement_up(mlx);
	else if (keycode == 1)
		movement_down(mlx);
	else if (keycode == 7)
		check_coins(mlx);
	ft_printf("Moves : [%d]\n", mlx->move);
	return (0);
}
