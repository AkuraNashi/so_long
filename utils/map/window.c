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

#include "../../so_long.h"

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
	if (w->map == NULL)
		return (NULL);
	w->mlx_win = mlx_new_window(w->mlx, w->map->c_max->x,
			w->map->c_max->y, "SO_SSBU");
	w->h = 0;
	w->w = 0;
	w->cp = temp;
	w->player = new_player(w->map->map);
	w->move = 0;
	w->coins = count_coins(w->map->map);
	w->start = count_player(w->map->map);
	w->exit = count_exit(w->map->map);
	w->file = av[1];
	w->count = 0;
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
	coords->y = (128 * i) + 128;
	coords->x = (128 * j);
	return (coords);
}

/// Permet d'afficher graphiquement la map
/// \param map la chaine de string
/// \param mlx la structure windows
/// \param y la hauteur ou placer les tiles
void	generate_map(t_mlx *mlx, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (mlx->map->map[i])
	{
		j = 0;
		while (mlx->map->map[i][j])
		{
			parse_texture(mlx, mlx->map->map[i][j], x, y);
			x += 128;
			j++;
		}
		x = 0;
		y += 128;
		i++;
	}
}

/// Permet de check la texture a dessiner
/// \param mlx la structure de la window
/// \param c la charactere a check
/// \param x coordonnees horizontal
/// \param y coordonnees verticale
void	parse_texture(t_mlx *mlx, char c, int x, int y)
{
	if (c == '1')
		drow_one_texture(x, y, mlx, "assets/Block.xpm");
	else if (c == 'C')
		drow_one_texture(x, y, mlx, "assets/Coin.xpm");
	else if (c == 'E')
		drow_one_texture(x, y, mlx, "assets/Exit.xpm");
	else if (c == 'P')
		drow_one_texture(x, y, mlx, "assets/Player.xpm");
	else if (c == 'B')
		drow_one_texture(x, y, mlx, "assets/Blue.xpm");
	else
		drow_one_texture(x, y, mlx, "assets/Terrain.xpm");
}

///Ferme la fenetre envoyer en parametres
/// \param mlx la structure window

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	free(mlx->cp);
	free(mlx->player->coords);
	free(mlx->player);
	free(mlx->map->c_max);
	free_tab((void *)mlx->map->map);
	free(mlx->map);
	free(mlx);
	exit(0);
}
