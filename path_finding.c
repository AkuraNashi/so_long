/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:48:00 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/11/16 15:48:01 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//i = y
//j = x
int	check_adjacent(t_mlx *mlx)
{
	void	*img;
	t_coords *c;
	char	**map;

	map = mlx->map->map;
	c = mlx->cp;
	//Haut
	if (map[c->y - 1][c->x] != '1')
	{
		img = mlx_xpm_file_to_image(mlx->mlx, "./Blue.xpm",
									&mlx->img_width, &mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, (128 * c->x), (128 * c->y) - 128);
		sleep(1);
	}
	//Droite
	if (map[c->y][c->x + 1] != '1')
	{
		img = mlx_xpm_file_to_image(mlx->mlx, "./Blue.xpm",
									&mlx->img_width, &mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, (128 * c->x) + 128, (128 * c->y));
		sleep(1);
	}
	//Bas
	if (map[c->y + 1][c->x] != '1')
	{
		img = mlx_xpm_file_to_image(mlx->mlx, "./Blue.xpm",
									&mlx->img_width, &mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, (128 * c->x), (128 * c->y) + 128);
		sleep(1);
	}
	//Gauche
	if (map[c->y][c->x - 1] != '1')
	{
		img = mlx_xpm_file_to_image(mlx->mlx, "./Blue.xpm",
									&mlx->img_width, &mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, (128 * c->x) - 128, (128 * c->y));
		sleep(1);
	}
	return (0);
}

void	recursive_path(t_mlx *mlx)
{
	char		**map;

	map = mlx->map->map;
	check_adjacent(mlx);
	mlx_loop_hook(mlx->mlx, check_adjacent, &mlx);

}

void	check_coins(t_mlx *mlx)
{
	char		**map;
	int			i;
	int			j;

	map = mlx->map->map;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				mlx->cp->x = j;
				mlx->cp->y = i;
				recursive_path(mlx);
			}
			j++;
		}
		i++;
	}
}