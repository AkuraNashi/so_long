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

///Permet  de calculer la taille de la fenetre en fonction de la map
/// \return la structure mlx
t_mlx	*new_mlx(char **av)
{
	t_mlx		*w;
	t_coords	*temp;

	temp = ft_calloc(1, sizeof(*temp));
	w = malloc(sizeof(*w));
	w->mlx = mlx_init();
	w->map = new_map(av[1]);
	w->mlx_win = mlx_new_window(w->mlx, w->map->c_max->x,
			w->map->c_max->y, "SO_SSBU");
	w->h = 0;
	w->w = 0;
	w->cp = temp;
	w->player = new_player(w->map->map);
	w->move = 0;
	w->coins = count_coins(w->map->map);
	w->file = av[1];
	return (w);
}

/// Calcule la taille de la fenetre
/// \param map le tableau en 2d
/// \return structure coords contenant la taille de la window
t_coords	*calculate_window_size(char **map)
{
	t_coords	*coords;
	int			i;
	int			j;

	coords = malloc(sizeof(*coords));
	i = 0;
	coords->x = 0;
	coords->y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	coords->y = 128 * i;
	coords->x = 128 * j;
	return (coords);
}

/// Permet d'afficher graphiquement la map
/// \param map la chaine de string
/// \param mlx la structure windows
/// \param y la hauteur ou placer les tiles

void	generate_map(char *map, t_mlx *mlx, int y)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (map[i])
	{
		if (map[i] == '1')
			drow_one_texture(x, y, mlx, "Block.xpm");
		else if (map[i] == 'C')
			drow_one_texture(x, y, mlx, "Coin.xpm");
		else if (map[i] == 'E')
			drow_one_texture(x, y, mlx, "Exit.xpm");
		else if (map[i] == 'P')
			drow_one_texture(x, y, mlx, "Player.xpm");
		else
			drow_one_texture(x, y, mlx, "Terrain.xpm");
		x += 128;
		i++;
	}
}
///Ferme la fenetre envoyer en parametres
/// \param mlx la structure window

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	free(mlx);
	exit(0);
}
