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

void	generate_map(char *map)
{
	while(*map)
	{
		printf("%c", *map);
		if(*map == '0')
			generate_tile("./Terrain.xpm");
		else if (*map == '1')
			generate_tile("./Block.xpm");
		else if (*map == 'E')
			generate_tile("./Exit.xpm");
		else if (*map == 'P')
			generate_tile("./Joker.xpm");
		else
			break ;

		map++;
	}
}
int	main(void)
{
//	void	*mlx;
//	void	*img;
//	void	*mlx_win;
//	char	*char_path = "./Joker.xpm";
//	char	*wall_path = "./Block.xpm";
//	int		img_width;
//	int		img_height;
	int i;
	int y;
	char *str;
	int fd;

	i = 0;
	y = 0;
	fd = open("map1.txt", O_RDONLY);
	str = "";
	printf("Voici la map : \n\n");
	while(str)
	{
		str = get_next_line(fd);
		if (str)
			generate_map(str);
	}
//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "So_SSBU");
//
//	img = mlx_xpm_file_to_image(mlx, wall_path, &img_width, &img_height);
//	img = mlx_xpm_file_to_image(mlx, char_path, &img_width, &img_height);
//	mlx_put_image_to_window(mlx, mlx_win, img, 256,256);
//	mlx_loop(mlx);
}
