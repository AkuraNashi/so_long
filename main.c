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
			coords->x += 128;
			j++;
		}
		coords->y += 128;
		i++;
	}
	return (coords);
}

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
			x += 128;
		i++;
	}
}

t_map	*new_map(int x, int y)
{
	t_map	*map;

	map = malloc(sizeof(*map));
	map->coords_max = malloc(sizeof(*(map->coords_max)));
	if (!map || !map->coords_max)
		return (NULL);
	map->map = fillmap("map1.txt");
	map->coords_max->x = x;
	map->coords_max->y = y;
	return (map);
}

int	main(void)
{
	t_map	*map;
	void	*mlx;
	void	*mlx_win;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = new_map(0, 0);
	map->coords_max = calculate_window_size(map->map);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "So_SSBU");
	while (map->map[j])
	{
		if (map->map)
			generate_map(map->map[j], mlx, mlx_win, i);
		i += 128;
		j++;
	}
	mlx_loop(mlx);
}
