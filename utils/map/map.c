/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:52:31 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/11/22 16:52:32 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

///Cree une map
/// \return la structure map

t_map	*new_map(char *str)
{
	t_map	*map;

	map = malloc(sizeof(*map));
	if (!map || !map->c_max)
		return (NULL);
	map->map = fillmap(str);
	if (map->map == NULL)
		return (NULL);
	map->c_max = calculate_window_size(map->map);
	return (map);
}
/// Permet de savoir la longueur de la chaine de characteres sans \n
/// \param str une chaine de charactere
/// \return	le nombre de characteres de cette ligne

size_t	ft_strnllen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
/// Remplit un tableau en 2d de la matrice
/// se trouvant dans le fichier donner en parametres
/// \param file fichier contenant al matrice
/// \return un tablea en 2d

char	**fillmap(char	*file)
{
	char	*line;
	char	**temp;
	int		fd;
	size_t	i;

	i = count_lines(file);
	temp = malloc((i + 1) * sizeof(char *));
	if (!temp)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		temp[i] = ft_substr(line, 0, ft_strnllen(line));
		if (temp[i++] == NULL)
			return (NULL);
		free(line);
		line = get_next_line(fd);
	}
	temp[i] = NULL;
	close(fd);
	return (temp);
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
	return (0);
}
