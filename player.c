/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:35:13 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/11/07 16:35:15 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Ajouter nom du joueur en parametres ?
t_entity	*new_player(char **map)
{
	t_entity	*player;

	player = malloc(sizeof(*player));
	player->coords = find_player(map);
	return (player);
}

t_coords	*find_player(char **map)
{
	t_coords	*coords;
	int			i;
	int			j;

	coords = malloc(sizeof(*coords));
	if (!coords)
		return (NULL);
	i = 0;
	coords->x = 0;
	coords->y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				coords->x = i;
				coords->y = j;
			}
			j++;
		}
		i++;
	}
	return (coords);
}

void	movement(t_mlx *mlx)
{
	t_coords	*loc;
	t_map		*map;
	void		*img;

	loc = mlx->player->coords;
	map = mlx->map;
	if (map->map[loc->y][loc->x + 1] != '1')
	{
		img = mlx_xpm_file_to_image(mlx->mlx, "./Player.xpm",
									&mlx->img_width, &mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, (loc->x * 128) + 128, loc->y * 128);
	}
	img = NULL;
	mlx->player->coords->x += 1;
	printf("apres : %d\n\n", mlx->player->coords->x);
}