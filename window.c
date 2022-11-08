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

t_coords	*calculate_window_size(char **map)
{
	int			i;
	int			j;
	t_coords	*coords;

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

void	generate_map(char *map, void *mlx, void *mlx_win, int y)
{
	int		i;
	int		x;
	void	*img;
	int		img_width;
	int		img_height;

	i = 0;
	x = 0;
	while (map[i])
	{
		if (map[i] == '1')
		{
			img = mlx_xpm_file_to_image(mlx, "./Block.xpm",
										&img_width, &img_height);
			mlx_put_image_to_window(mlx, mlx_win, img, x, y);
			x += 128;
		}
		else if (map[i] == 'C')
		{
			img = mlx_xpm_file_to_image(mlx, "./Coin.xpm",
										&img_width, &img_height);
			mlx_put_image_to_window(mlx, mlx_win, img, x, y);
			x += 128;
		}
		else if (map[i] == 'E')
		{
			img = mlx_xpm_file_to_image(mlx, "./Exit.xpm",
										&img_width, &img_height);
			mlx_put_image_to_window(mlx, mlx_win, img, x, y);
			x += 128;
		}
		else if (map[i] == 'P')
		{
			img = mlx_xpm_file_to_image(mlx, "./Player.xpm",
										&img_width, &img_height);
			mlx_put_image_to_window(mlx, mlx_win, img, x, y);
			x += 128;
		}
		else
		{
			img = mlx_xpm_file_to_image(mlx, "./Terrain.xpm",
										&img_width, &img_height);
			mlx_put_image_to_window(mlx, mlx_win, img, x, y);
			x += 128;
		}
		i++;
	}
}