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

/// Cree une structure player
/// \param map tableau en 2d
/// permettant de savoir ou est le joueur
/// \return la structure player
t_entity	*new_player(char **map)
{
	t_entity	*player;

	player = malloc(sizeof(*player));
	player->coords = find_player(map);
	player->coins = 0;
	printf("new player player : [%p]\n", player);
	printf("new player player coords: [%p]\n", player->coords);
	return (player);
}

///Permet de savoir ou est le joueur dans la matrice
/// \param map tableau en 2d
/// \return return la coordonnes du joueur

t_coords	*find_player(char **map)
{
	t_coords	*coords;
	int			i;
	int			j;

	coords = malloc(sizeof(*coords));
	printf("find player coords : [%p]\n", coords);
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
				coords->x = j;
				coords->y = i;
			}
			j++;
		}
		i++;
	}
	printf("find player coords : [%p]\n", coords);
	return (coords);
}
