/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:55:26 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/11/27 22:55:27 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// Check l'extension du fichier
/// \param av nom du fichier
/// \return 0 si ce n'est pas bon
int	check_strname(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (!(av[i - 1] == 'r'
			&& av[i - 2] == 'e'
			&& av[i - 3] == 'b'
			&& av[i - 4] == '.'))
		return (0);
	return (1);
}
