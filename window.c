/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:31:20 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/11/03 20:31:22 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Permet  de calculer la taille
// de la fenetre en fonction de la map

t_mlx	*new_mlx(t_map *map)
{
	t_mlx	*window;

	window = malloc(sizeof(*window));
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, map->coords_max->x,
			map->coords_max->y, "SO_SSBU");
	window->img_height = 0;
	window->img_width = 0;
	window->map = new_map();
	window->player = new_player(map->map);
	return (window);
}

t_coords	*calculate_window_size(char **map)
{
	t_coords	*coords;
	int			i;
	int			j;

	coords = malloc(sizeof(*coords));
	i = 0;
	j = 0;
	coords->x = 0;
	coords->y = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '\n')
				coords->x += 128;
			j++;
		}
		coords->y += 128;
		i++;
	}
	return (coords);
}

//Permet d'afficher graphiquement la map

void	generate_map(char *map, t_mlx *mlx, int y)
{
	int		i;
	int		x;
	void	*img;

	i = 0;
	x = 0;
	while (map[i])
	{
		if (map[i] == '1')
		{
			img = mlx_xpm_file_to_image(mlx->mlx, "./Block.xpm",
					&mlx->img_width, &mlx->img_height);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, x, y);
			x += 128;
		}
		else if (map[i] == 'C')
		{
			img = mlx_xpm_file_to_image(mlx->mlx, "./Coin.xpm",
					&mlx->img_width, &mlx->img_height);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, x, y);
			x += 128;
		}
		else if (map[i] == 'E')
		{
			img = mlx_xpm_file_to_image(mlx->mlx, "./Exit.xpm",
					&mlx->img_width, &mlx->img_height);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, x, y);
			x += 128;
		}
		else if (map[i] == 'P')
		{
			img = mlx_xpm_file_to_image(mlx->mlx, "./Player.xpm",
					&mlx->img_width, &mlx->img_height);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, x, y);
			x += 128;
		}
		else
		{
			img = mlx_xpm_file_to_image(mlx->mlx, "./Terrain.xpm",
					&mlx->img_width, &mlx->img_height);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, x, y);
			x += 128;
		}
		i++;
	}
}
