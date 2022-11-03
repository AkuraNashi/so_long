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

//0 emplacement vide
//1 mur
//C item a collecter
//E exit
//P position depart
void	*generate_map(char *map, void *mlx, void *mlx_win, int y)
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
		else if(map[i] == 'C')
		{
			img = mlx_xpm_file_to_image(mlx, "./Coin.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(mlx, mlx_win, img, x, y);
			x += 128;
		}
		else if(map[i] == 'E')
		{
			img = mlx_xpm_file_to_image(mlx, "./Exit.xpm",
										&img_width, &img_height);
			mlx_put_image_to_window(mlx, mlx_win, img, x, y);
			x += 128;
		}
		else if(map[i] == 'P')
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
	return (img);
}

int	main(void)
{
	void	*mlx;
	void	*img;
	void	*mlx_win;
	char	*str;
	int		fd;
	int		i;

	fd = open("map1.txt", O_RDONLY);
	str = "";
	mlx = mlx_init();
	i = 0;
	mlx_win = mlx_new_window(mlx, 1920, 1080, "So_SSBU");
	//Permet de generer toutes les tiles
	while (str)
	{
		str = get_next_line(fd);
		if (str)
			img = generate_map(str, mlx, mlx_win, i);
		i += 128;
	}
	mlx_loop(mlx);
}
