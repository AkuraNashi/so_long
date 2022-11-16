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

void	movement_right(t_mlx *mlx)
{
	t_coords	*loc;
	t_map		*map;
	void		*img;

	loc = mlx->player->coords;
	map = mlx->map;
	if (map->map[loc->y][loc->x + 1] != '1' && map->map[loc->y][loc->x + 1] != 'E')
	{
		if (mlx->player->coins == mlx->coins && map->map[loc->y][loc->x + 1] == 'E')
		{
			system("clear");
			printf("Gagnez !!!!\n\n");
			close_window(mlx);
		}
		img = mlx_xpm_file_to_image(mlx->mlx, "./Terrain.xpm",
				&mlx->img_width, &mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, (loc->x * 128), loc->y * 128);
		img = mlx_xpm_file_to_image(mlx->mlx, "./Player.xpm",
				&mlx->img_width, &mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, (loc->x * 128) + 128, loc->y * 128);
		if(map->map[loc->y][loc->x + 1] == 'C')
		{
			map->map[loc->y][loc->x + 1] = '0';
			mlx->player->coins++;
		}
		mlx->player->coords->x += 1;
		mlx->move++;
	}
	img = NULL;
}

void	movement_left(t_mlx *mlx)
{
	t_coords	*loc;
	t_map		*map;
	void		*img;
	int 		move;

	move = 0;
	loc = mlx->player->coords;
	map = mlx->map;
	if (map->map[loc->y][loc->x - 1] != '1' && map->map[loc->y][loc->x - 1] != 'E')
	{
		if (mlx->player->coins == mlx->coins && map->map[loc->y][loc->x - 1] == 'E')
		{
			system("clear");
			printf("Gagnez !!!!\n\n");
			close_window(mlx);
		}
		img = mlx_xpm_file_to_image(mlx->mlx, "./Terrain.xpm",
									&mlx->img_width, &mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, (loc->x * 128), loc->y * 128);
		img = mlx_xpm_file_to_image(mlx->mlx, "./Player.xpm",
									&mlx->img_width, &mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, (loc->x * 128) - 128, loc->y * 128);
		if(map->map[loc->y][loc->x - 1] == 'C')
		{
			map->map[loc->y][loc->x - 1] = '0';
			mlx->player->coins++;
		}
		mlx->player->coords->x -= 1;
		mlx->move++;
	}
	img = NULL;
}

void	movement_up(t_mlx *mlx)
{
	t_coords	*loc;
	t_map		*map;
	void		*img;

	loc = mlx->player->coords;
	map = mlx->map;
	if (map->map[loc->y - 1][loc->x] != '1' && map->map[loc->y - 1][loc->x] != 'E')
	{
		if (mlx->player->coins == mlx->coins && map->map[loc->y - 1][loc->x] == 'E')
		{
			system("clear");
			printf("Gagnez !!!!\n\n");
			close_window(mlx);
		}
		img = mlx_xpm_file_to_image(mlx->mlx, "./Terrain.xpm",
									&mlx->img_width, &mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, (loc->x * 128), loc->y * 128);
		img = mlx_xpm_file_to_image(mlx->mlx, "./Player.xpm",
									&mlx->img_width, &mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, (loc->x * 128), (loc->y * 128)- 128);
		if(map->map[loc->y - 1][loc->x] == 'C')
		{
			map->map[loc->y - 1][loc->x] = '0';
			mlx->player->coins++;
		}
		mlx->player->coords->y -= 1;
		mlx->move++;
	}
	img = NULL;
}

void	movement_down(t_mlx *mlx)
{
	t_coords	*loc;
	t_map		*map;
	void		*img;

	loc = mlx->player->coords;
	map = mlx->map;
	if (map->map[loc->y + 1][loc->x] != '1' && map->map[loc->y + 1][loc->x] != 'E')
	{
		if (mlx->player->coins == mlx->coins && map->map[loc->y + 1][loc->x] == 'E')
		{
			system("clear");
			printf("Gagnez !!!!\n\n");
			close_window(mlx);
		}
		img = mlx_xpm_file_to_image(mlx->mlx, "./Terrain.xpm",
									&mlx->img_width, &mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, (loc->x * 128), loc->y * 128);
		img = mlx_xpm_file_to_image(mlx->mlx, "./Player.xpm",
									&mlx->img_width, &mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, (loc->x * 128), (loc->y * 128) + 128);
		if(map->map[loc->y + 1][loc->x] == 'C')
		{
			map->map[loc->y + 1][loc->x] = '0';
			mlx->player->coins++;
		}
		mlx->player->coords->y += 1;
		mlx->move++;
	}
	img = NULL;
}