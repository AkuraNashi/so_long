/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:33:25 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/10/31 21:33:30 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


//Remplit le **map de la t_struct via le fichier .txt

char	**fillmap(char	*file)
{
	char	*line;
	char	**temp;
	t_map	*map;
	int		fd;
	size_t	i;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	i = ft_strlen(line) - 1;
	temp = malloc(i * sizeof(char *));
	if (!temp)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	i = 0;
	while (line)
	{
		temp[i] = ft_substr(line, 0, ft_strlen(line));
		if (temp[i] == NULL)
			return (NULL);
		line = get_next_line(fd);
		i++;
	}
	temp[i] = NULL;
	map->map = temp;
	close(fd);
	return (map->map);
}

//Cree une map

t_map	*new_map(void)
{
	t_map	*map;

	map = malloc(sizeof(*map));
	map->coords_max = malloc(sizeof(*(map->coords_max)));
	if (!map || !map->coords_max)
		return (NULL);
	map->map = fillmap("map1.txt");
	map->coords_max->x = 0;
	map->coords_max->y = 0;
	return (map);
}

int	main(void)
{
	t_map	*map;
	t_entity *player;
	t_coords	*coords;
	void	*mlx;
	void	*mlx_win;
	int		i;
	int		j;

	map = new_map();
	map->coords_max = calculate_window_size(map->map);
	coords = find_player(map->map);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map->coords_max->x,
			map->coords_max->y, "So_SSBU");
	i = 0;
	j = 0;
	while (map->map[j])
	{
		if (map->map)
			generate_map(map->map[j], mlx, mlx_win, i);
		i += 128;
		j++;
	}
	mlx_loop(mlx);
}
